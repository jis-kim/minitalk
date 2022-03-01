/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:56:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/01 18:19:45 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERR_ARG 0
# define ERR_SEND 1
# define ERR_HDL 2

# include <signal.h>
# include "ft_printf.h"

void	print_error(int type);

#endif
