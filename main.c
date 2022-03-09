/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:03:13 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/09 14:44:51 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	name[] = "sumin";
	int		age = 28;
	int		neg = -8;
	int		int_min = -2147483648;
	int		my_cnt = 0;
	int		real_cnt = 0;
	int		hex = 16;

	// printf("sizeof(char *) : %ld, sizeof(unsigned char *) : %ld\n", sizeof(char *), sizeof(unsigned char *));

	printf("<my printf>\n");
	my_cnt = ft_printf("my name is %s.\ni am %d.\nhow was %d years?\n", name, age, neg);
	printf("my cnt : %d\n\n", my_cnt);
	my_cnt += ft_printf("int min : %d\nun_int : %u\n", int_min, hex);
	printf("my cnt : %d\n\n", my_cnt);
	my_cnt += ft_printf("hex_x : %x\nhex_X : %X%%\n", hex, hex);
	printf("my cnt : %d\n", my_cnt);

	printf("\n<real printf>\n");
	real_cnt = printf("my name is %s.\ni am %d.\nhow was %d years?\n", name, age, neg);
	printf("real cnt : %d\n\n", real_cnt);
	real_cnt += printf("int min : %d\nun_int : %u\n", int_min, hex);
	printf("real cnt : %d\n\n", real_cnt);
	real_cnt += printf("hex_x : %x\nhex_X : %X%%\n", hex, hex);
	printf("real cnt : %d\n", real_cnt);
}
