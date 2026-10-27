/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:21:50 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:59:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	store_instruction(char *instruction, t_move	*move)
{
	if (!ft_strcmp(instruction, "sa\n"))
		*move = m_sa;
	else if (!ft_strcmp(instruction, "sb\n"))
		*move = m_sb;
	else if (!ft_strcmp(instruction, "ss\n"))
		*move = m_ss;
	else if (!ft_strcmp(instruction, "pa\n"))
		*move = m_pa;
	else if (!ft_strcmp(instruction, "pb\n"))
		*move = m_pb;
	else if (!ft_strcmp(instruction, "ra\n"))
		*move = m_ra;
	else if (!ft_strcmp(instruction, "rb\n"))
		*move = m_rb;
	else if (!ft_strcmp(instruction, "rr\n"))
		*move = m_rr;
	else if (!ft_strcmp(instruction, "rra\n"))
		*move = m_rra;
	else if (!ft_strcmp(instruction, "rrb\n"))
		*move = m_rrb;
	else if (!ft_strcmp(instruction, "rrr\n"))
		*move = m_rrr;
	else
		*move = m_err;
}

void	execute_moves(t_cl_list *a, t_cl_list *b, t_cl_list *set, int verbose)
{
	t_move		move;
	t_cl_list	*runner;

	runner = set->next;
	while (runner != set)
	{
		move = *(t_move *)runner->data;
		do_move(a, b, move, verbose);
		runner = runner->next;
	}
}
