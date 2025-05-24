/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:37:56 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/05/09 13:54:55 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_point_hex(unsigned long long num)
{
	int			count_len;
	const char	*hold;

	count_len = 0;
	hold = "0123456789abcdef";
	if (num < 16)
	{
		ft_putchar_fd(hold[num], 1);
		return (1);
	}
	else
	{
		count_len += ft_point_hex(num / 16);
		ft_putchar_fd(hold[num % 16], 1);
		return (count_len + 1);
	}
}

int	ft_print_point(unsigned long long c)
{
	unsigned long long	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	if (c == 0)
	{
		ft_putchar_fd('0', 1);
		return (len + 1);
	}
	else
		return (len + ft_point_hex(c));
}

// #include <stdio.h>
// int main(int ac , char *av[])
// {
//     if(ac > 1) {
//         int test_value = ft_atoi(av[1]);
//         int value = ft_atoi(av[1]);

//         int result = ft_print_point(test_value);
//         printf("\n");
//         printf("ans len = %d" , result);
//         printf("\n");
//         printf("printf = %p" , test_value);
//     }
// }