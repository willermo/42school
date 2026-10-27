/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:29:29 by doriani           #+#    #+#             */
/*   Updated: 2023/02/27 11:28:07 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_substring(char *str, char *sub)
{
	while (*sub)
		if (*str++ != *sub++)
			return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find && is_substring(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
