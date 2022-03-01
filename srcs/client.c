/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/02 04:41:10 by jiskim           ###   ########.fr       */
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
	g_index--;
	if (signal == SIGUSR1 && g_index != -1)
		print_error(ERR_HDL);
	ft_printf("signal %d\n", signal);
	return ;
}

int send_one_char(int pid, char ch)
{
	int	index;

	index = 7;
	while (index >= 0)
	{
		if (kill(pid, (ch >> index & 1) | 30))
			return (ERR_SEND);
		ft_printf("%d\n", 7 - index);
		pause();
		write(1, "pause 1\n", 8);
		index--;
		//if (g_index != index)
		//{
		//	write(1,"diff\n",5);
		//	int	ret = 10;
		//	while (ret-- > 0)
		//	{
		//		kill(pid, SIGUSR1);
		//		pause();
		//	}
		//	print_error(ERR_HDL);
		//}
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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigreceive;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	i = 0;
	while (argv[2][i])
	{
		ret = send_one_char(server, argv[2][i++]);
		if (ret > 0)
			print_error(ret);
	}
	ret = 8;
	while (ret-- > 0)
	{
		kill(server, SIGUSR1);
		pause();
	}
	send_one_char(server, '\0'); //success
	ft_printf("Success!");
	return (EXIT_SUCCESS);
}
