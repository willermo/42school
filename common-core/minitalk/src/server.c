/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:26:45 by doriani           #+#    #+#             */
/*   Updated: 2023/04/19 17:26:49 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	msg_handler(int sig_no, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				bit;
	static unsigned char	message[4096];

	(void)context;
	if (sig_no == SIGUSR1)
		ch |= (1 << bit % 8);
	if (bit++ == 0)
		ft_printf("Message from client @%d: ", info->si_pid);
	if (bit % 8 == 0)
	{
		if (ch == '\0')
		{
			write(1, message, bit / 8);
			write(1, "\n", 1);
			ft_bzero(message, bit / 8);
			bit = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			message[bit / 8 - 1] = ch;
			ch = '\0';
		}
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf("Error starting server.\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = msg_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Hello from server. Send me a message @%d!\n", pid);
	while (1)
		pause();
	return (0);
}
