/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:43:40 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/04 14:38:43 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(long long num)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*hold;
	size_t	len;

	num = n;
	len = ft_num_len(num);
	hold = (char *)malloc(sizeof(char) * (len + 1));
	if (!hold)
		return (0);
	hold[len] = '\0';
	len--;
	if (num == 0)
		*hold = '0';
	if (num < 0)
	{
		num *= -1;
		*hold = '-';
	}
	while (num > 0)
	{
		hold[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (hold);
}

// #include <stdio.h>
// int main(void)
// {
//     int test = -1234644;
//     printf("ans = %d\n" , test);
// }