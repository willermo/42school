/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:15:20 by doriani           #+#    #+#             */
/*   Updated: 2023/03/01 16:10:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*runner;

	i = 0;
	runner = dest;
	while (*src && i < n)
	{
		*runner++ = *src++;
		i++;
	}
	while (i < n)
	{
		*runner++ = '\0';
		i++;
	}
	return (dest);
}
