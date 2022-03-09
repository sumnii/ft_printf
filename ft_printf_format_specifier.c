/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:56:09 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/09 15:10:00 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char_str(va_list ap, char c)
{
	int		cnt;
	char	*str;

	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
	{
		str = va_arg(ap, char *);
		cnt = 0;
		if (!str)
			return (write(1, "(null)", 6));
		while (*str)
		{
			cnt += ft_putchar(*str);
			++str;
		}
		return (cnt);
	}
	return (0);
}

int	ft_put_ptr(va_list ap)
{
	unsigned char	*ptr;

	ptr = va_arg(ap, unsigned char *);
	printf("%hhn\n", ptr);

	return (0);
}

int	ft_put_integer(va_list ap, char c)
{
	long	nb;
	int		cnt;

	nb = va_arg(ap, int);
	cnt = 0;
	if (c == 'u' && nb < 0)
		ft_putnbr(-nb, &cnt);
	else
		ft_putnbr(nb, &cnt);
	return (cnt);
}

int	ft_put_unsigned(va_list ap)
{
	unsigned int	nb;
	unsigned int	nb_copy;
	int				len;
	char			*space;

	len = 1;
	nb = va_arg(ap, unsigned int);
	nb_copy = nb;
	while (nb_copy > 10)
	{
		nb_copy = nb_copy / 10;
		++len;
	}
	space = (char *)calloc(sizeof(char), len + 1);
	if (!space)
		return (0);
	nb_copy = len;
	while (len >= 0)
	{
		space[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	len = write(1, space, nb_copy + 1);
	// free (space);
	return (len);
}

int	ft_put_hex(va_list ap, char c)
{
	unsigned int	nb;
	int				cnt;
	char			*hex_lower;
	char			*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	nb = va_arg(ap, unsigned int);
	cnt = 0;
	if (c == 'x')
		ft_putnbr_base(hex_lower, nb, &cnt);
	else if (c == 'X')
		ft_putnbr_base(hex_upper, nb, &cnt);
	return (cnt);
}