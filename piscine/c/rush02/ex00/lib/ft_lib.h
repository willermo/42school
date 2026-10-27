/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:31:56 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 12:18:22 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_char_is_numeric(char c);
int		ft_char_is_space(char c);
void	ft_putstring(char *str);
char	*ft_substr(char str[], int start, int end, int skip_zeroes);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);
#endif
