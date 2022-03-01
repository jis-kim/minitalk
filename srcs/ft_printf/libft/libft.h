/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:43:21 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/01 15:32:36 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_putstr(char *s, int len);
void	ft_putendl_fd(char *s, int fd);

#endif
