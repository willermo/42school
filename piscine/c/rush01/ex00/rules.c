/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:58:39 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 19:45:50 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*skip_blanks(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

char	*skip_token(char *str)
{
	while (*str && !(*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

int validate(char *str)
{
	int count;

	count = 0;
	while (*(str = skip_blanks(str)))
	{
		if (*str == '0')
		{
			while (*str == '0')
		   		str++;
			if (*str < '1' || *str > '9')
				return (0);
		}
		while (*str >= '0' && *str <= '9')
			str ++;
		if (*str && !(*str == ' ' || *str == '\t'))
			return (0);
		count++;
	}
	return (count % 4) ? 0 : count;
}

int	*get_rules(int dim, char *str)
{
	int		*rules;
	int		*runner;

	rules = (int *) malloc(dim * 4 * sizeof(int));
	runner = rules;
	str = skip_blanks(str);
	while (*(str = skip_blanks(str)))
	{
		*runner++ = atoi(str);
		str = skip_token(str);
	}
	return (rules);
}
