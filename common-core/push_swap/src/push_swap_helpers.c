/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:17:11 by doriani           #+#    #+#             */
/*   Updated: 2023/06/04 12:59:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_data(void *v1, void *v2)
{
	return (*(int *)v1 - *(int *)v2);
}

void	*dup_data(void *value)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	*new_value = *(int *)value;
	return ((void *) new_value);
}

void	*store_int(int value)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	*new_value = value;
	return (new_value);
}

int	push_is_good(t_cl_list *node, t_cl_list *stack_b)
{
	if (cmp_data(node->data, stack_b->next->data) > 0)
	{
		if (cmp_data(node->data, stack_b->prev->data) < 0)
			return (1);
		if (cl_get_max_node(stack_b, cmp_data) == stack_b->next)
			return (1);
	}
	if (cmp_data(node->data, stack_b->prev->data) < 0)
		if (cl_get_min_node(stack_b, cmp_data) == stack_b->prev)
			return (1);
	return (0);
}

int	pos_is_borderline(t_cl_list *stack, t_cl_list *node, t_cl_list *runner)
{
	if (cl_get_min_node(stack, cmp_data) == runner \
	&& cl_get_max_node(stack, cmp_data) == runner->next \
	&& (cmp_data(node->data, runner->data) < 0 \
		|| cmp_data(node->data, runner->next->data) > 0))
		return (1);
	return (0);
}
