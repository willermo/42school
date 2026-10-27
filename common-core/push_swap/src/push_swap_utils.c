/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:16:30 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 13:37:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_mark(t_cl_list *stack_a, t_cl_list *mark, int verbose)
{
	int	pos;

	pos = cl_get_node_position(stack_a, mark->data, cmp_data);
	mark = cl_get_node_by_position(stack_a, pos);
	if (pos > cl_size(stack_a) / 2 + 1)
	{
		while (stack_a->next != mark)
			rra(stack_a, verbose);
	}
	else
	{
		while (stack_a->next != mark)
			ra(stack_a, verbose);
	}
}

void	rotate_to_min_stack_a(t_cl_list *stack_a, int verbose)
{
	int			min_position;
	t_cl_list	*min_node;

	if (cl_is_empty(stack_a))
		return ;
	min_position = cl_get_min_node_position(stack_a, cmp_data);
	min_node = cl_get_min_node(stack_a, cmp_data);
	if (min_position > cl_size(stack_a) / 2 + 1)
	{
		while (stack_a->next != min_node)
			rra(stack_a, verbose);
	}
	else
	{
		while (stack_a->next != min_node)
			ra(stack_a, verbose);
	}
}

void	stack_swap(t_cl_list *stack)
{
	if (cl_size(stack) > 1)
		cl_swap_list_nodes_by_position(stack, 1, 2);
}

void	stack_push(t_cl_list *from, t_cl_list *to)
{
	if (cl_is_empty(from))
		return ;
	cl_add_node_begin(to, cl_remove_node(from->next));
}

void	stack_rotate(t_cl_list *stack, t_direction direction)
{
	cl_rotate(stack, direction);
}
