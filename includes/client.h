/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:56:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/25 20:38:58 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define ERR_ARG 0
# define ERR_SEND 1

# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

void	print_error(int type);

#endif
