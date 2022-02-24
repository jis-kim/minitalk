/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:45 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/24 21:13:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sigpile(int signal, siginfo_t *sit, void *oact)
{
	ft_printf("signal is %d\n", sit->si_signo);
	oact = NULL;
	if (signal == SIGUSR1 || signal == SIGUSR2)
		ft_printf("%d\n", 1&signal);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("I'm server!! and my pid is %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.__sigaction_u.__sa_sigaction = sigpile;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (EXIT_SUCCESS);
}
