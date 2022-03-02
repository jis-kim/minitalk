/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:45 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/02 22:01:15 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigpile(int signal, siginfo_t *sit, void *oact)
{
	static char	ch = 0;
	static int	i = 0;
	static int	client = -1;
	static char	buf[BUF_SIZE];
	static int	len = 0;

	oact = NULL;
	if (sit->si_pid)
		client = sit->si_pid;
	ch = (ch << 1) | (1 & signal);
	i++;
	if (i == 8)
	{
		i = 0;
		buf[len++] = ch;
		if (len == BUF_SIZE - 1 || ch == 0)
		{
			write(1, buf, len);
			len = 0;
		}
		if (ch == 0)
		{
			kill(client, SIGUSR1);
			return ;
		}
		ch = 0;
	}
	if (kill(client, SIGUSR2))
		print_error(ERR_SEND);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid is %d\n", getpid());
	//sigemptyset(&sa.sa_mask);
	//sigaddset(&sa.sa_mask, SIGUSR1);
	//sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigpile;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
