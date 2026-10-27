/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:56:00 by doriani           #+#    #+#             */
/*   Updated: 2023/02/20 18:12:16 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reset_num(char *num)
{
	num[0] = '0';
	num[1] = '0';
}

void	set_next_greater_number(char *num1, char *num2)
{
	if (num1[1] < '9')
	{
		num2[0] = num1[0];
		num2[1] = num1[1] + 1;
	}
	else if (num1[0] < '9')
	{
		num2[0] = num1[0] + 1;
		num2[1] = '0';
	}
	else
		reset_num(num2);
}

void	inc_num(char *num)
{
	if (num[1] < '9')
	{
		num[1]++;
	}
	else if (num[0] < '9' && num[1] == '9')
	{
		num[0]++;
		num[1] = '0';
	}
	else
	{
		reset_num(num);
	}
}

void	write_combination(char *num1, char *num2)
{
	char	space;
	char	*sep;

	space = ' ';
	sep = ", ";
	write(1, num1, 2);
	write(1, &space, 1);
	write(1, num2, 2);
	if (num1[0] != '9' || num1[1] != '8' \
	|| num2[0] != '9' || num2[1] != '9')
		write(1, sep, 2);
}

void	ft_print_comb2(void)
{
	char	num1[3];
	char	num2[3];
	int		i;

	i = 0;
	while (i < 3)
	{
		num1[i] = 0;
		num2[i] = 0;
		i++;
	}
	reset_num(num1);
	while (!(num1[0] == '9' && num1[1] == '9'))
	{
		set_next_greater_number(num1, num2);
		while (!(num2[0] == '0' && num2[1] == '0'))
		{
			write_combination(num1, num2);
			inc_num(num2);
		}
		inc_num(num1);
	}
}


int main(void)
{
	ft_print_comb2();
}
