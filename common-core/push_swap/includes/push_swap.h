/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:16:12 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 12:05:43 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef enum e_move
{
	m_sa,
	m_ss,
	m_pa,
	m_sb,
	m_pb,
	m_ra,
	m_rb,
	m_rr,
	m_rra,
	m_rrb,
	m_rrr,
	m_null,
	m_err
}	t_move;
void	free_argument(char **elements);
int		add_argument(t_cl_list **stack, char *arg);
void	sort_three(t_cl_list *stack, int verbose);
void	cheapsort(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
void	rotate_to_mark(t_cl_list *stack_a, t_cl_list *mark, int verbose);
void	rotate_to_min_stack_a(t_cl_list *stack_a, int verbose);
void	stack_swap(t_cl_list *stack);
void	stack_push(t_cl_list *from, t_cl_list *to);
void	stack_rotate(t_cl_list *stack, t_direction direction);
int		cmp_data(void *v1, void *v2);
void	*dup_data(void *value);
void	*store_int(int value);
int		push_is_good(t_cl_list *node, t_cl_list *stack_b);
int		pos_is_borderline(t_cl_list *stack, t_cl_list *node, t_cl_list *runner);
int		is_valid_integer(char *str);
int		is_valid_stack(t_cl_list *stack);
int		stack_is_sorted(t_cl_list *stack, t_sort_order order);
void	sa(t_cl_list *stack_a, int verbose);
void	sb(t_cl_list *stack_b, int verbose);
void	ss(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
void	pa(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
void	pb(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
void	ra(t_cl_list *stack_a, int verbose);
void	rb(t_cl_list *stack_b, int verbose);
void	rr(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
void	rra(t_cl_list *stack_a, int verbose);
void	rrb(t_cl_list *stack_b, int verbose);
void	rrr(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
void	do_cheapest_move(t_cl_list *stack_a, t_cl_list *stack_b, int verbose);
t_move	*get_moves_sequence(t_cl_list *stack_a, t_cl_list *stack_b, \
							t_cl_list *node);
void	set_a_rotations(t_cl_list *node, t_cl_list *stack_a, int *rot_a);
void	set_b_rotations(t_cl_list *node, t_cl_list *stack_b, int *rot_b);
void	set_total_operations(int *rot_a, int *rot_b, int *total_ops);
int		get_min_operations(int *ops);
t_move	*get_fwd_fwd_sequence(int rot_a, int rot_b, int ops);
t_move	*get_fwd_rev_sequence(int rot_a, int rot_b, int ops);
t_move	*get_rev_fwd_sequence(int rot_a, int rot_b, int ops);
t_move	*get_rev_rev_sequence(int rot_a, int rot_b, int ops);
int		get_moves_sequence_cost(t_move *moves_sequence);
void	do_move(t_cl_list *stack_a, t_cl_list *stack_b, t_move move, \
						int verbose);
void	do_moves_sequence(t_cl_list *stack_a, t_cl_list *stack_b, \
						t_move *moves_sequence, int verbose);
#endif
