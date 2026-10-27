/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:02:11 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:59:46 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_argument(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
		free(elements[i++]);
	free(elements);
}

int	add_argument(t_cl_list **stack, char *arg)
{
	char	**elements;
	int		i;

	elements = ft_split(arg, " \t\n\v\f\r");
	i = 0;
	while (elements[i])
	{
		if (!is_valid_integer(elements[i]))
		{
			free_argument(elements);
			return (0);
		}
		cl_insert_end(*stack, store_int(ft_atoi(elements[i++])));
	}
	free_argument(elements);
	return (1);
}

int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

int	is_valid_stack(t_cl_list *stack)
{
	t_cl_list	*node;
	t_cl_list	*next_node;

	node = stack->next;
	while (node != stack)
	{
		next_node = node->next;
		while (next_node != stack)
		{
			if (*(int *)node->data == *(int *)next_node->data)
				return (0);
			next_node = next_node->next;
		}
		node = node->next;
	}
	return (1);
}

int	stack_is_sorted(t_cl_list *stack, t_sort_order order)
{
	return (cl_is_sorted(stack, order, cmp_data));
}
