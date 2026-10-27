/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:58:52 by doriani           #+#    #+#             */
/*   Updated: 2023/02/24 10:05:46 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_memory_address(void *addr)
{
	unsigned long	address;
	char			digits[16];
	int				i;

	address = (unsigned long) addr;
	i = 0;
	while (address)
	{
		if (address % 16 >= 10)
			digits[i++] = address % 16 - 10 + 'a';
		else
			digits[i++] = address % 16 + '0';
		address /= 16;
	}
	while (i < 16)
		digits[i++] = '0';
	i--;
	while (i >= 0)
		write(1, &digits[i--], 1);
	write(1, ": ", 2);
}

void	write_hex_char(void *addr)
{
	unsigned char	hex_val[2];

	if (*(unsigned char *) addr % 16 >= 10)
		hex_val[1] = *(unsigned char *) addr % 16 - 10 + 'a';
	else
		hex_val[1] = *(unsigned char *) addr % 16 + '0';
	if (*(unsigned char *) addr / 16 >= 10)
		hex_val[0] = *(unsigned char *) addr / 16 - 10 + 'a';
	else
		hex_val[0] = *(unsigned char *) addr / 16 + '0';
	write(1, hex_val, 2);
}

void	write_char(void *addr)
{
	if (*(unsigned char *) addr >= 32 && *(unsigned char *) addr <= 126)
		write(1, ((unsigned char *) addr), 1);
	else
		write(1, ".", 1);
}

void	write_line(void *addr, unsigned int bufsize)
{
	unsigned int	i;

	i = 0;
	write_memory_address(addr);
	while (i < bufsize)
	{
		write_hex_char(addr + i);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < bufsize)
	{
		write_char(addr + i);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	offset;
	unsigned int	remaining_locations;
	unsigned int	bufsize;

	offset = 0;
	remaining_locations = size;
	while (offset < size)
	{
		if (remaining_locations >= 16)
			bufsize = 16;
		else
			bufsize = remaining_locations;
		remaining_locations -= bufsize;
		write_line(addr + offset, bufsize);
		offset += bufsize;
	}
	return (addr);
}
