/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sequences_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:11:46 by doriani           #+#    #+#             */
/*   Updated: 2023/06/04 12:55:23 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*get_fwd_fwd_sequence(int rot_a, int rot_b, int ops)
{
	t_move	*moves_sequence;
	int		i;

	moves_sequence = (t_move *) malloc(sizeof(t_move) * (ops + 1));
	i = 0;
	while (rot_a && rot_b)
	{
		moves_sequence[i++] = m_rr;
		rot_a--;
		rot_b--;
	}
	while (rot_a)
	{
		moves_sequence[i++] = m_ra;
		rot_a--;
	}
	while (rot_b)
	{
		moves_sequence[i++] = m_rb;
		rot_b--;
	}
	moves_sequence[i] = m_null;
	return (moves_sequence);
}

t_move	*get_fwd_rev_sequence(int rot_a, int rot_b, int ops)
{
	t_move	*moves_sequence;
	int		i;

	moves_sequence = (t_move *) malloc(sizeof(t_move) * (ops + 1));
	i = 0;
	while (rot_a)
	{
		moves_sequence[i++] = m_ra;
		rot_a--;
	}
	while (rot_b)
	{
		moves_sequence[i++] = m_rrb;
		rot_b--;
	}
	moves_sequence[i] = m_null;
	return (moves_sequence);
}

t_move	*get_rev_fwd_sequence(int rot_a, int rot_b, int ops)
{
	t_move	*moves_sequence;
	int		i;

	moves_sequence = (t_move *) malloc(sizeof(t_move) * (ops + 1));
	i = 0;
	while (rot_a)
	{
		moves_sequence[i++] = m_rra;
		rot_a--;
	}
	while (rot_b)
	{
		moves_sequence[i++] = m_rb;
		rot_b--;
	}
	moves_sequence[i] = m_null;
	return (moves_sequence);
}

t_move	*get_rev_rev_sequence(int rot_a, int rot_b, int ops)
{
	t_move	*moves_sequence;
	int		i;

	moves_sequence = (t_move *) malloc(sizeof(t_move) * (ops + 1));
	i = 0;
	while (rot_a && rot_b)
	{
		moves_sequence[i++] = m_rrr;
		rot_a--;
		rot_b--;
	}
	while (rot_a)
	{
		moves_sequence[i++] = m_rra;
		rot_a--;
	}
	while (rot_b)
	{
		moves_sequence[i++] = m_rrb;
		rot_b--;
	}
	moves_sequence[i] = m_null;
	return (moves_sequence);
}
