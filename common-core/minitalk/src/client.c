/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:26:31 by doriani           #+#    #+#             */
/*   Updated: 2023/04/19 17:26:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_byte(int pid, char byte)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & (1 << bit++))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(USLEEPTIME);
	}
}

static void	msg_handler(int sig_no)
{
	if (sig_no == SIGUSR2)
	{
		ft_printf("Message sent!\n");
		exit(EXIT_SUCCESS);
	}
}

static int	check_params(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server pid] [message]\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error: server %s not found.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	size_t				i;

	pid = check_params(argc, argv);
	signal(SIGUSR2, msg_handler);
	i = 0;
	while (1)
		send_byte(pid, argv[2][i++]);
	return (0);
}
