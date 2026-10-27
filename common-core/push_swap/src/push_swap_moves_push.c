/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:26:41 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:46:35 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	stack_push(stack_b, stack_a);
	if (verbose)
		ft_putendl("pa");
}

void	pb(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	stack_push(stack_a, stack_b);
	if (verbose)
		ft_putendl("pb");
}
