/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:46:59 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/30 12:35:35 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr(long nb, int *cnt)
{
	if (nb < 0)
	{
		nb = -nb;
		*cnt += ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, cnt);
		*cnt += ft_putchar(nb % 10 + '0');
	}
	else
		*cnt += ft_putchar(nb + '0');
}

void	ft_putnbr_base(char *base, unsigned long nb, int *cnt)
{
	if (nb >= 16)
	{
		ft_putnbr_base(base, nb / 16, cnt);
		*cnt += ft_putchar(base[nb % 16]);
	}
	else
		*cnt += ft_putchar(base[nb]);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = 0;
		--n;
	}
}

void	*ft_my_calloc(size_t count, size_t size)
{
	void	*ary;

	ary = malloc(count * size);
	if (!ary)
		return (NULL);
	ft_bzero(ary, count * size);
	return (ary);
}
