/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:25:35 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/31 12:45:36 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_uint{
	unsigned int	nb;
	unsigned int	nb_copy;
	int				len;
}				t_uint;

int		ft_printf(const char *str, ...);
int		ft_after_percent(va_list ap, const char *str);

int		ft_put_char_str(va_list ap, char c);
int		ft_put_ptr(va_list ap);
int		ft_put_integer(va_list ap, char c);
int		ft_put_unsigned(va_list ap);
int		ft_put_hex(va_list ap, char c);

int		ft_putchar(char c);
void	ft_putnbr(long nb, int *cnt);
void	ft_putnbr_base(char *base, unsigned long nb, int *cnt);
void	ft_bzero(void *s, size_t n);
void	*ft_my_calloc(size_t count, size_t size);

#endif
