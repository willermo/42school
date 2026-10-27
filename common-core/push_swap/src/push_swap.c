/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:37:42 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 12:06:04 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(int count, char **elements, t_cl_list **a, t_cl_list **b)
{
	int	i;

	if (count < 2)
		exit(EXIT_FAILURE);
	i = 1;
	*a = cl_init_list();
	while (i < count)
	{
		if (!add_argument(a, elements[i++]))
		{
			ft_putstr_fd("Error\n", 2);
			cl_destroy_list(a);
			exit(EXIT_FAILURE);
		}
	}
	if (!is_valid_stack(*a))
	{
		ft_putstr_fd("Error\n", 2);
		cl_destroy_list(a);
		exit(EXIT_FAILURE);
	}
	*b = cl_init_list();
}

static void	cleanup(t_cl_list **a, t_cl_list **b)
{
	cl_destroy_list(a);
	cl_destroy_list(b);
}

int	main(int argc, char **argv)
{
	t_cl_list	*stack_a;
	t_cl_list	*stack_b;

	init(argc, argv, &stack_a, &stack_b);
	if (cl_size(stack_a) < 2 || stack_is_sorted(stack_a, ascending))
		;
	else if (cl_size(stack_a) == 2)
		sa(stack_a, 1);
	else if (cl_size(stack_a) == 3)
		sort_three(stack_a, 1);
	else
		cheapsort(stack_a, stack_b, 1);
	cleanup(&stack_a, &stack_b);
	return (0);
}
