/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:25:04 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/08 22:38:25 by sumsong          ###   ########.fr       */
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
		{
			write(1, &(*str), 1);
			++cnt;
		}
		++str;
	}
	va_end(ap);
	return (cnt);
}

int	ft_after_percent(va_list ap, const char *str)
{
	if (*str == '%')
		return (write(1, "%", 1));
	else if (*str == 'c' || *str == 's')
		return (ft_put_char_str(ap, *str));
	else if (*str == 'p')
		return (0);
	else if (*str == 'd' || *str == 'i')
		return (ft_put_integer(ap, *str));
	else if (*str == 'u')
		return (ft_put_unsigned(ap));
	else if (*str == 'x' || *str == 'X')
		return (ft_put_hex(ap, *str));
	return (0);
}
