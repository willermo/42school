/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:26:38 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:47:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_cl_list *stack_a, int verbose)
{
	stack_rotate(stack_a, straight);
	if (verbose)
		ft_putendl("ra");
}

void	rb(t_cl_list *stack_b, int verbose)
{
	stack_rotate(stack_b, straight);
	if (verbose)
		ft_putendl("rb");
}

void	rr(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	stack_rotate(stack_a, straight);
	stack_rotate(stack_b, straight);
	if (verbose)
		ft_putendl("rr");
}
