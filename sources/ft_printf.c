/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:03:24 by f██████           #+#    #+#             */
/*   Updated: 2021/12/02 18:29:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	put_va(va_list args, const char *fmt, int *i)
{
	while (*fmt)
	{
		if (fmt[0] == '%' && fmt[1] != '\0' && ft_strchr("scdiupxX%", fmt[1]))
		{
			if (fmt[1] == 's')
				*i += puts_fd(va_arg(args, char *), 1);
			else if (fmt[1] == 'c')
				*i += putc_fd(va_arg(args, int), 1);
			else if (fmt[1] == 'd' || fmt[1] == 'i')
				*i += putdi_fd(va_arg(args, int), 1);
			else if (fmt[1] == 'u')
				*i += putu_fd(va_arg(args, int), 1);
			else if (fmt[1] == 'p')
				*i += putp_fd(va_arg(args, unsigned long long), 1) + 1;
			else if (fmt[1] == 'x')
				*i += putx1_fd(va_arg(args, unsigned long long), 1);
			else if (fmt[1] == 'X')
				*i += putx2_fd(va_arg(args, unsigned long long), 1);
			else if (fmt[1] == '%')
				*i += putc_fd(fmt[1], 1);
			fmt = fmt + 2;
		}
		else
			*i += putc_fd(fmt++[0], 1);
	}
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, fmt);
	put_va(args, fmt, &i);
	va_end(args);
	return (i);
}
