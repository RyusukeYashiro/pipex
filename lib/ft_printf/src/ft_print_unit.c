/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 03:35:14 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/17 13:02:06 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_uni_num_len(unsigned int c)
{
	int	num_len;

	num_len = 0;
	if (c == 0)
		num_len = 1;
	while (c > 0)
	{
		c /= 10;
		num_len++;
	}
	return (num_len);
}

char	*ft_uitoa(unsigned int c)
{
	char	*str;
	int		len;

	len = ft_uni_num_len(c);
	 str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (c == 0)
		*str = '0';
	len--;
	while (c > 0 && len >= 0)
	{
		str[len] = (c % 10) + '0';
		c /= 10;
		len--;
	}
	return (str);
}

int	ft_print_unit(unsigned int c)
{
	unsigned int	len;
	char			*hold;

	len = 0;
	hold = ft_uitoa(c);
	len = ft_print_str(hold);
	free(hold);
	return (len);
}

// #include <stdio.h>
// int main(int ac , char *av[])
// {
//     if(ac > 1)
//     {
//         int a = ft_atoi(av[1]);
//         unsigned int test = ft_print_unit(a);
//         printf("\n");
//         printf("test_len  = %d" , test);
//         printf("\n");
//         printf("printf = %u" , a);
//     }
//     return (0);
// }