/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:27:40 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/28 15:40:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(int type)
{
	if (type == ERR_ARG)
		write(STDERR_FILENO, "Argument Error\n", 15);
	else if (type == ERR_SEND)
		write(STDERR_FILENO, "Send Error\n", 11);
	exit(EXIT_FAILURE);
}
