/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:45 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/01 21:58:18 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigpile(int signal, siginfo_t *sit, void *oact)
{
	static char	ch;
	static int	i;

	oact = NULL;
	if (sit->si_pid == 0)
	{
		ft_putendl_fd("\n\nrequest failed. try again!\n", 1);
		ch = 0;
		i = 0;
		return ;
	}
	ch = (ch << 1) | (1 & signal);
	i++;
	if (i == 8)
	{
		i = 0;
		if (ch == 0)
		{
			kill(sit->si_pid, SIGUSR1);
			return ;
		}
		write(1, &ch, 1);
		ch = 0;
	}
	kill(sit->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("I'm server!! and my pid is %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.__sigaction_u.__sa_sigaction = sigpile;
	if (sigaction(SIGUSR1, &sa, NULL))
		print_error(ERR_ARG);
	if (sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	while(1)
		pause();
	return (EXIT_SUCCESS);
}
