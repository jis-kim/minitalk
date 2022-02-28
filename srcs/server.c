/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:45 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/28 21:25:57 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigpile(int signal, siginfo_t *sit, void *oact)
{
	static char	ch;
	static int	i;

	ft_printf("signal info is %d\n", sit->si_code);
	oact = NULL;
	ch = (ch << 1) + (1 & signal);
	if (kill(sit->si_pid, signal))
		print_error(ERR_SEND);
	i++;
	if (i == 8)
	{
		ft_printf("%c", ch);
		ch = 0;
		i = 0;
	}
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
