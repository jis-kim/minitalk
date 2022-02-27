/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/28 01:34:23 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int send_one_char(int pid, char ch)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (kill(pid, (ch >> i & 1) + 30))
			return -1;
		usleep(200);
		i--;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	int	server;
	int	i;

	if (argc != 3)
		print_error(ERR_ARG);
	ft_printf("I'm client!!!!!, %s\n", argv[1]);
	server = ft_atoi(argv[1]);
	if (server == 0)
		print_error(ERR_ARG);
	i = 0;
	while (argv[2][i])
		if (send_one_char(server, argv[2][i++]))
			print_error(ERR_SEND);
	return (EXIT_SUCCESS);
}
