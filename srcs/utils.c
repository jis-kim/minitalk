/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:27:40 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/01 21:18:34 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(int type)
{
	if (type == ERR_ARG)
		ft_putendl_fd("Argument Error", STDERR_FILENO);
	else if (type == ERR_SEND)
		ft_putendl_fd("Send Error", STDERR_FILENO);
	else if (type == ERR_HDL)
		ft_putendl_fd("Handler Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
