/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:17:35 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:53:22 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*get_moves_sequence(t_cl_list *stack_a, t_cl_list *stack_b, \
							t_cl_list *node)
{
	t_move	*moves_sequence;
	int		rot_a[2];
	int		rot_b[2];
	int		total_ops[4];
	int		min_ops;

	set_a_rotations(node, stack_a, rot_a);
	set_b_rotations(node, stack_b, rot_b);
	set_total_operations(rot_a, rot_b, total_ops);
	min_ops = get_min_operations(total_ops);
	if (total_ops[0] == min_ops)
		moves_sequence = get_fwd_fwd_sequence(rot_a[0], rot_b[0], min_ops);
	else if (total_ops[1] == min_ops)
		moves_sequence = get_fwd_rev_sequence(rot_a[0], rot_b[1], min_ops);
	else if (total_ops[2] == min_ops)
		moves_sequence = get_rev_fwd_sequence(rot_a[1], rot_b[0], min_ops);
	else if (total_ops[3] == min_ops)
		moves_sequence = get_rev_rev_sequence(rot_a[1], rot_b[1], min_ops);
	return (moves_sequence);
}

int	get_moves_sequence_cost(t_move *moves_sequence)
{
	int	i;

	i = 0;
	while (moves_sequence[i] != m_null)
		i++;
	return (i);
}

void	do_move(t_cl_list *stack_a, t_cl_list *stack_b, t_move move, \
					int verbose)
{
	if (move == m_sa)
		sa(stack_a, verbose);
	else if (move == m_sb)
		sb(stack_b, verbose);
	else if (move == m_ss)
		ss(stack_a, stack_b, verbose);
	else if (move == m_pa)
		pa(stack_a, stack_b, verbose);
	else if (move == m_pb)
		pb(stack_a, stack_b, verbose);
	else if (move == m_ra)
		ra(stack_a, verbose);
	else if (move == m_rb)
		rb(stack_b, verbose);
	else if (move == m_rr)
		rr(stack_a, stack_b, verbose);
	else if (move == m_rra)
		rra(stack_a, verbose);
	else if (move == m_rrb)
		rrb(stack_b, verbose);
	else if (move == m_rrr)
		rrr(stack_a, stack_b, verbose);
}

void	do_moves_sequence(t_cl_list *stack_a, t_cl_list *stack_b, \
						t_move *moves_sequence, int verbose)
{
	int	i;

	i = 0;
	while (moves_sequence[i] != m_null)
		do_move(stack_a, stack_b, moves_sequence[i++], verbose);
}
