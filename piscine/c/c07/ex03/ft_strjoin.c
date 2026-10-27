/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:54:31 by doriani           #+#    #+#             */
/*   Updated: 2023/03/08 13:49:01 by doriani          ###   ########.fr       */
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

char	*copy_token(char *str, char*token)
{
	return (ft_strcpy(str, token) + ft_strlen(token));
}

int	get_buffer_size(int size, char **strings, char *sep)
{
	int	i;
	int	buffer_size;

	i = 0;
	buffer_size = 0;
	while (i < size)
		buffer_size += ft_strlen(strings[i++]);
	buffer_size += (size - 1) * ft_strlen(sep) + 1;
	return (buffer_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		buffer_size;
	int		i;
	char	*runner;

	if (size == 0)
	{
		join = (char *) malloc(sizeof (char));
		join[0] = '\0';
		return (join);
	}
	i = 0;
	buffer_size = get_buffer_size(size, strs, sep);
	join = (char *) malloc(buffer_size * sizeof(char));
	runner = join;
	i = 0;
	while (i < size - 1)
	{
		runner = copy_token(runner, strs[i++]);
		runner = copy_token(runner, sep);
	}
	runner = copy_token(runner, strs[i]);
	return (join);
}
