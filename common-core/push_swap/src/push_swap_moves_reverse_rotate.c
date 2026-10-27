/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:26:22 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:47:15 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_cl_list *stack_a, int verbose)
{
	stack_rotate(stack_a, reverse);
	if (verbose)
		ft_putendl("rra");
}

void	rrb(t_cl_list *stack_b, int verbose)
{
	stack_rotate(stack_b, reverse);
	if (verbose)
		ft_putendl("rrb");
}

void	rrr(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	stack_rotate(stack_a, reverse);
	stack_rotate(stack_b, reverse);
	if (verbose)
		ft_putendl("rrr");
}
