/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:43:22 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 11:21:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static void	exit_error(t_cl_list **a, t_cl_list **b, t_cl_list **s)
{
	ft_putstr_fd("Error\n", 2);
	if (a != NULL)
		cl_destroy_list(a);
	if (b != NULL)
		cl_destroy_list(b);
	if (s != NULL)
		cl_destroy_list(s);
	exit(EXIT_FAILURE);
}

static int	init_set(t_cl_list **set)
{
	char	*instruction;
	t_move	*move;

	*set = cl_init_list();
	instruction = get_next_line(0);
	while (instruction)
	{
		move = (t_move *)malloc(sizeof(t_move));
		store_instruction(instruction, move);
		if (*move == m_err)
		{
			free(move);
			return (0);
		}
		cl_insert_end(*set, move);
		free(instruction);
		instruction = get_next_line(0);
	}
	return (1);
}

static void	init(int ac, char **av, t_cl_list **a, t_cl_list **b)
{
	int	i;

	if (ac < 2)
		exit(EXIT_FAILURE);
	i = 1;
	*a = cl_init_list();
	while (i < ac)
	{
		if (!add_argument(a, av[i++]))
			exit_error(a, NULL, NULL);
	}
	if (!is_valid_stack(*a))
		exit_error(a, NULL, NULL);
	*b = cl_init_list();
}

static void	cleanup(t_cl_list **a, t_cl_list **b, t_cl_list **set)
{
	cl_destroy_list(a);
	cl_destroy_list(b);
	cl_destroy_list(set);
}

int	main(int argc, char **argv)
{
	t_cl_list	*stack_a;
	t_cl_list	*stack_b;
	t_cl_list	*set;

	init(argc, argv, &stack_a, &stack_b);
	if (!init_set(&set))
		exit_error(&stack_a, &stack_b, &set);
	execute_moves(stack_a, stack_b, set, 0);
	if (stack_is_sorted(stack_a, ascending) && cl_is_empty(stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(&stack_a, &stack_b, &set);
	return (0);
}
