/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:20:27 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:48:25 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_cl_list *stack_a, int verbose)
{
	stack_swap(stack_a);
	if (verbose)
		ft_putendl("sa");
}

void	sb(t_cl_list *stack_b, int verbose)
{
	stack_swap(stack_b);
	if (verbose)
		ft_putendl("sb");
}

void	ss(t_cl_list *stack_a, t_cl_list *stack_b, int verbose)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
	if (verbose)
		ft_putendl("ss");
}
