/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:06:40 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 12:05:45 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_cl_list *stack, int verbose)
{
	if (cl_is_sorted(stack, ascending, cmp_data))
		return ;
	else if (cl_is_sorted(stack, descending, cmp_data))
	{
		sa(stack, verbose);
		rra(stack, verbose);
		return ;
	}
	else if (cmp_data(stack->next->data, stack->next->next->data) > 0)
	{
		if (cmp_data(stack->next->data, stack->next->next->next->data) > 0)
			ra(stack, verbose);
		else
			sa(stack, verbose);
	}
	else
	{
		if (cmp_data(stack->next->data, stack->next->next->next->data) > 0)
			rra(stack, verbose);
		else
		{
			sa(stack, verbose);
			ra(stack, verbose);
		}
	}
}

void	do_cheapest_move(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	t_cl_list	*runner;
	t_move		*best_moves_sequence;
	t_move		*candidate_moves_sequence;

	runner = stack_a->next;
	best_moves_sequence = get_moves_sequence(stack_a, stack_b, runner);
	runner = runner->next;
	while (runner->data && get_moves_sequence_cost(best_moves_sequence) > 0)
	{
		candidate_moves_sequence = get_moves_sequence(stack_a, stack_b, runner);
		if (get_moves_sequence_cost(candidate_moves_sequence) \
			< get_moves_sequence_cost(best_moves_sequence))
		{
			free(best_moves_sequence);
			best_moves_sequence = candidate_moves_sequence;
		}
		else
			free(candidate_moves_sequence);
		runner = runner->next;
	}
	do_moves_sequence(stack_a, stack_b, best_moves_sequence, verbose);
	free(best_moves_sequence);
	pb(stack_a, stack_b, verbose);
}

static t_cl_list	*get_mark(t_cl_list *stack_a, t_cl_list *stack_b)
{
	t_cl_list	*mark;

	mark = stack_a->next;
	if (cmp_data(stack_a->next->data, stack_b->next->data) > 0 \
	&& cmp_data(stack_a->prev->data, stack_b->next->data) < 0)
		return (mark);
	if (cl_is_sorted(stack_a, ascending, cmp_data) \
	&& cmp_data(stack_a->prev->data, stack_b->next->data) < 0)
		return (mark);
	while (mark->next->data)
	{
		if (cmp_data(mark->data, stack_b->next->data) > 0 \
		&& cl_get_min_node(stack_a, cmp_data) == mark)
			return (mark);
		if (cmp_data(mark->data, stack_b->next->data) < 0 \
		&& cl_get_min_node(stack_a, cmp_data) == mark->next)
			return (mark->next);
		if (cmp_data(mark->data, stack_b->next->data) < 0 \
		&& cmp_data(mark->next->data, stack_b->next->data) > 0)
			return (mark->next);
		mark = mark->next;
	}
	return (mark);
}

void	cheapsort(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	pb(stack_a, stack_b, verbose);
	pb(stack_a, stack_b, verbose);
	while (cl_size(stack_a) > 3)
	{
		do_cheapest_move(stack_a, stack_b, verbose);
	}
	sort_three(stack_a, verbose);
	while (!cl_is_empty(stack_b))
	{
		rotate_to_mark(stack_a, get_mark(stack_a, stack_b), verbose);
		pa(stack_a, stack_b, verbose);
	}
	rotate_to_min_stack_a(stack_a, verbose);
}
