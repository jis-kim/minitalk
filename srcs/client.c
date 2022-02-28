/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/28 21:06:19 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_index = 7;

void	sigreceive(int signal, siginfo_t *sit, void *oact)
{
	oact = NULL;
	g_index--;
	if ()
}

int send_one_char(int pid, char ch, int *r_index)
{
	if (*r_index < 0)
		*r_index = 7;
	g_index = 7;
	while (*r_index >= 0)
	{
		if (kill(pid, (ch >> (*r_index) & 1) + 30))
			return (-1);
		usleep(200);
		if (*r_index != *r_index)
			return (1);
		*r_index--;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	int	server;
	int	i;
	static int	r_index = 7;
	struct sigaction	sa;

	if (argc != 3)
		print_error(ERR_ARG);
	server = ft_atoi(argv[1]);
	if (server == 0)
		print_error(ERR_ARG);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.__sigaction_u.__sa_sigaction = sigreceive;
	if (sigaction(SIGUSR1, &sa, NULL))
		print_error(ERR_ARG);
	if (sigaction(SIGUSR2, &sa, NULL))
		print_error(ERR_ARG);
	i = 0;
	while (argv[2][i])
		if (send_one_char(server, argv[2][i++], &r_index))
			print_error(ERR_SEND);
	ft_printf("Success!");
	return (EXIT_SUCCESS);
}
