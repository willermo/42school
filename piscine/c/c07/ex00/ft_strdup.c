/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:10:33 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 15:11:02 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*runner;

	runner = dest;
	while (*src)
		*runner++ = *src++;
	*runner = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = (char *) malloc((ft_strlen(src) + 1) * sizeof (char));
	if (! dup)
		return (0);
	ft_strcpy(dup, src);
	return (dup);
}
