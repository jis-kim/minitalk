/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:51:23 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/25 20:37:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define ERR_ARG 0
# define ERR_SEND 1

# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

void	print_error(int type);

#endif
