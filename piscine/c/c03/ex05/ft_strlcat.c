/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:11:43 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 10:37:17 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*p;

	p = dest;
	while (size != 0 && *p != '\0')
	{
		p++;
		size--;
	}
	if (size != 0)
	{
		while (--size != 0)
		{
			*p = *src;
			if (*p == '\0')
				return (p - dest);
			p++;
			src++;
		}
		*p = '\0';
	}
	return ((p - dest) + ft_strlen(src));
}
