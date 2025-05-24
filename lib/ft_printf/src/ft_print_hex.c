/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:57:42 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/09 20:08:06 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_put_hex(unsigned int num, const char format)
{
	int			count;
	const char	*hold_x_up;
	const char	*hold_x_low;

	hold_x_up = "0123456789ABCDEF";
	hold_x_low = "0123456789abcdef";
	count = 0;
	if (num < 16)
	{
		if (format == 'X')
			ft_putchar_fd(hold_x_up[num], 1);
		else
			ft_putchar_fd(hold_x_low[num], 1);
		return (1);
	}
	else
	{
		count += ft_put_hex(num / 16, format);
		if (format == 'X')
			ft_putchar_fd(hold_x_up[num % 16], 1);
		else
			ft_putchar_fd(hold_x_low[num % 16], 1);
	}
	return (count + 1);
}

int	ft_print_hex(unsigned int c, const char format)
{
	if (c == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
		return (ft_put_hex(c, format));
}

// #include <stdio.h>
// int main(int ac , char *av[])
// {
//     if(ac > 2) {
//         int suuti = ft_atoi(av[1]);
//         char format = av[2][0];
//         if(!(format == 'x' || format == 'X'))
//             return (0);
//         int result = ft_put_hex(suuti , format);
//         printf("\n");
//         printf("ans len = %d" , result);
//         printf("\n");
//         printf("printf = %x" , ft_atoi(av[1]));
//     }
// }

// gcc -I../include -I../libft ft_print_alpha.c -L../libft -lft-o ft_print_alpha