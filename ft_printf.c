/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:25:04 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/30 12:37:43 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_after_percent(va_list ap, const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, str);
	cnt = 0;
	while (*str)
	{
		if (*str == '%')
			cnt += ft_after_percent(ap, ++str);
		else
			cnt += ft_putchar(*str);
		++str;
	}
	va_end(ap);
	return (cnt);
}

int	ft_after_percent(va_list ap, const char *str)
{
	if (*str == '%')
		return (ft_putchar('%'));
	else if (*str == 'c' || *str == 's')
		return (ft_put_char_str(ap, *str));
	else if (*str == 'p')
		return (ft_put_ptr(ap));
	else if (*str == 'd' || *str == 'i')
		return (ft_put_integer(ap, *str));
	else if (*str == 'u')
		return (ft_put_unsigned(ap));
	else if (*str == 'x' || *str == 'X')
		return (ft_put_hex(ap, *str));
	return (0);
}
