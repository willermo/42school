/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sequences_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:14:09 by doriani           #+#    #+#             */
/*   Updated: 2023/06/04 13:02:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_a_rotations(t_cl_list *node, t_cl_list *stack_a, int *rot_a)
{
	int			pos;
	int			size;
	t_cl_list	*runner;

	runner = stack_a->next;
	pos = 0;
	size = cl_size(stack_a);
	while (runner != node)
	{
		pos++;
		runner = runner->next;
	}
	rot_a[0] = pos;
	rot_a[1] = size - pos;
}

void	set_b_rotations(t_cl_list *node, t_cl_list *stack_b, int *rot_b)
{
	int			pos;
	int			size;
	t_cl_list	*runner;

	if (push_is_good(node, stack_b))
	{
		rot_b[0] = 0;
		rot_b[1] = 0;
		return ;
	}
	runner = stack_b->next;
	pos = 0;
	size = cl_size(stack_b);
	while (runner->next != stack_b \
	&& !(cmp_data(node->data, runner->data) < 0 \
		&& cmp_data(node->data, runner->next->data) > 0))
	{
		if (pos_is_borderline(stack_b, node, runner))
			break ;
		pos++;
		runner = runner->next;
	}
	rot_b[0] = pos + 1;
	rot_b[1] = size - pos - 1;
}

void	set_total_operations(int *rot_a, int *rot_b, int *total_ops)
{
	total_ops[0] = ft_min(rot_a[0], rot_b[0]) + ft_abs(rot_a[0] - rot_b[0]);
	total_ops[1] = rot_a[0] + rot_b[1];
	total_ops[2] = rot_a[1] + rot_b[0];
	total_ops[3] = ft_min(rot_a[1], rot_b[1]) + ft_abs(rot_a[1] - rot_b[1]);
}

int	get_min_operations(int *ops)
{
	int	min_ops;

	min_ops = ops[0];
	if (ops[1] < min_ops)
		min_ops = ops[1];
	if (ops[2] < min_ops)
		min_ops = ops[2];
	if (ops[3] < min_ops)
		min_ops = ops[3];
	return (min_ops);
}
