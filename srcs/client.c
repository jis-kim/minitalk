/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/01 21:55:11 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_index = 7;

void	sigreceive(int signal, siginfo_t *sit, void *oact)
{
	if (g_index < 0)
		g_index = 7;
	oact = NULL;
	sit = NULL;
	if (signal == SIGUSR1 && g_index != 0)
		print_error(ERR_HDL);
	g_index--;
	return ;
}

int send_one_char(int pid, char ch)
{
	int	index;
	int	trash;

	index = 7;
	while (index >= 0)
	{
		if (kill(pid, (ch >> (index) & 1) | 30))
			return (ERR_SEND);
		(index)--;
		usleep(500);
		if(g_index != index)
		{
			if (g_index < 0)
				g_index += 8;
			trash = g_index - index;
			while (trash-- > 0)
			{
				kill(pid, SIGUSR1);
				usleep(500);
			}
			return (ERR_HDL);
		}
	}
	return 0;
}

int	main(int argc, char **argv)
{
	int	server;
	int	i;
	struct sigaction	sa;
	int	ret;

	if (argc != 3)
		print_error(ERR_ARG);
	server = ft_atoi(argv[1]);
	if (server == 0)
		print_error(ERR_ARG);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.__sigaction_u.__sa_sigaction = sigreceive;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	i = 0;
	while (argv[2][i])
	{
		ret = send_one_char(server, argv[2][i++]);
		if (ret == ERR_HDL)
		{
			ret = 16;
			while (ret--)
			{
				kill(server, SIGUSR1);
				usleep(500);
			}
		}
		if (ret > 0)
			print_error(ret);
	}
	send_one_char(server, '\0');
	ft_printf("Success!");
	return (EXIT_SUCCESS);
}
