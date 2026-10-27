/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:09 by doriani           #+#    #+#             */
/*   Updated: 2023/06/06 10:49:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

void	store_instruction(char *instruction, t_move	*move);
void	execute_moves(t_cl_list *a, t_cl_list *b, t_cl_list *set, int verbose);
#endif
