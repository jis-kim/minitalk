/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:45 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/02 04:45:53 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigpile(int signal, siginfo_t *sit, void *oact)
{
	static char	ch;
	static int	i;
	static int	client = -1;

	oact = NULL;
	if (client == -1)
		client = sit->si_pid;
	if (sit->si_pid != client)
	{
		//ft_putendl_fd("\n\nrequest failed. try again!\n", 1);
		kill(client, SIGUSR1);
		//ch = 0;
		//i = 0;
		//client = -1;
		return ;
	}
	ch = (ch << 1) | (1 & signal);
	ft_printf("%d\n", i);
	i++;
	if (i >= 8)
	{
		if (ch == 0) //success
		{
			kill(client, SIGUSR1);
			client = -1;
			return ;
		}
		write(1, &ch, 1);
		i = 0;
		ch = 0;
	}
	ft_printf("before kill %d\n", i - 1);
	kill(client, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("I'm server!! and my pid is %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = sigpile;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	while(1)
		pause();
	return (EXIT_SUCCESS);
}
