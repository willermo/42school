/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:09:17 by doriani           #+#    #+#             */
/*   Updated: 2023/02/21 07:57:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowerchar(char *ch)
{
	if (*ch >= 'a' && *ch <= 'z')
		return (1);
	return (0);
}

int	is_upperchar(char *ch)
{
	if (*ch >= 'A' && *ch <= 'Z')
		return (1);
	return (0);
}

int	is_numchar(char *ch)
{
	if (*ch >= '0' && *ch <= '9')
		return (1);
	return (0);
}

int	is_alphanumchar(char *ch)
{
	if (is_lowerchar(ch) || is_upperchar(ch) || is_numchar(ch))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		in_the_word;
	char	*idx;

	in_the_word = 0;
	idx = str;
	while (*idx)
	{
		if (! is_alphanumchar(idx))
		{
			in_the_word = 0;
			idx++;
			continue ;
		}
		else
		{
			if (!in_the_word && is_lowerchar(idx))
				*idx -= 32;
			else if (in_the_word && is_upperchar(idx))
				*idx += 32;
			in_the_word = 1;
			idx++;
		}
	}
	return (str);
}
