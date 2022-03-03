/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:45 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/03 16:05:58 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(int pid, int signal)
{
	if (kill(pid, signal))
		print_error(ERR_SEND);
}

void	sigpile(int signal, siginfo_t *sit, void *oact)
{
	static char	ch = 0;
	static int	i = 0;
	static int	client = -1;
	static char	buf[BUF_SIZE];

	oact = NULL;
	if (sit->si_pid)
		client = sit->si_pid;
	ch = (ch << 1) | (1 & signal);
	if (!(++i & 7))
	{
		buf[(i >> 3)] = ch;
		if ((i >> 3) + 1 == BUF_SIZE - 1 || ch == 0)
		{
			write(1, buf, (i >> 3) + 1);
			i = 0;
			if (ch == 0)
			{
				ft_kill(client, SIGUSR1);
				return ;
			}
		}
		ch = 0;
	}
	ft_kill(client, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid is %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigpile;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
