/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2021/12/02 18:30:36 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(int n, int fd);
int		putp_fd(unsigned long long pnt, int fd);
int		puts_fd(char *s, int fd);
int		putc_fd(char c, int fd);
int		putdi_fd(int n, int fd);
int		putu_fd(int n, int fd);
int		putx1_fd(int n, int fd);
int		putx2_fd(int n, int fd);
char	*ull_to_hex(uint64_t ull);
char	*i_to_hex(uint64_t ull);
int		ft_printf(const char *fmt, ...);

#endif