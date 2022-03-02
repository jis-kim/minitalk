/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/02 22:01:08 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_end(int pid)
{
	static int	index = 0;

	if (index < 8)
	{
		if (kill(pid, SIGUSR1))
			print_error(ERR_SEND);
		index++;
		if (index < 8)
			return (0);
	}
	return (1);
}

int	send_next_bit(int pid, char *str)
{
	static char	*msg = NULL;
	static char	ch = 0;
	static int	index = -1;
	static int	server = -1;

	if (server == -1)
		server = pid;
	if (!msg && str)
		msg = str;
	if (index == -1 && msg)
	{
		ch = *msg;
		index = 7;
		msg++;
	}
	if (index >= 0 && ch)
	{
		if (kill(server, (ch >> index & 1) | 30))
			print_error(ERR_SEND);
		index--;
		return (0);
	}
	if (!ch)
		return (send_end(server));
	return (1);
}

void	sigreceive(int signal, siginfo_t *sit, void *oact)
{
	static int	end = 0;

	oact = NULL;
	if (signal == SIGUSR1)
	{
		if (end == 1)
			ft_putendl_fd("Success!", STDOUT_FILENO);
		if (end == 0)
			print_error(ERR_HDL);
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR2)
		end = send_next_bit(sit->si_pid, NULL);
	return ;
}

int	main(int argc, char **argv)
{
	int					server;
	struct sigaction	sa;

	if (argc != 3)
		print_error(ERR_ARG);
	server = ft_atoi(argv[1]);
	if (server == 0)
		print_error(ERR_ARG);
	//sigemptyset(&sa.sa_mask);
	//sigaddset(&sa.sa_mask, SIGUSR1);
	//sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigreceive;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	send_next_bit(server, argv[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
