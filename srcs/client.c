/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/24 21:53:16 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	print_error(int type)
{
	if (type == ERR_ARG)
		write(STDERR_FILENO, "Argument Error\n", 15);
	exit(EXIT_FAILURE);
}

int

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
	{
		send_one_char(argv[2][i]);
	}
	kill(server, SIGUSR1);
	return (EXIT_SUCCESS);
}
