/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:57:16 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 22:49:33 by doriani          ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*p;

	p = dest;
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
