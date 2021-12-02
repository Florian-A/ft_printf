/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:30:00 by f██████           #+#    #+#             */
/*   Updated: 2021/12/02 18:30:18 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;

	n1 = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = -n;
	}
	if (n1 <= 9)
		ft_putchar_fd(n1 + '0', fd);
	else
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putnbr_fd(n1 % 10, fd);
	}
}
