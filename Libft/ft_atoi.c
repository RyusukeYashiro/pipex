/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:33:59 by ryyashir          #+#    #+#             */
/*   Updated: 2024/12/12 10:29:15 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static void	ft_check(const char **string, int *sign)
{
	while (ft_isspace(**string))
		(*string)++;
	if (**string == '-' || **string == '+')
	{
		if (**string == '-')
			*sign *= -1;
		(*string)++;
	}
}

static int	overflow_check(int sign, long tmp, long hold)
{
	long	mx;
	long	mn;

	mx = LONG_MAX;
	mn = LONG_MIN;
	if (sign > 0)
	{
		if (mx / 10 < hold || ((mx / 10 == hold) && (mx % 10 < tmp)))
			return (1);
	}
	else
	{
		if (mn / -10 < hold || ((mn / -10 == hold) && (mn % -10 * -1 < tmp)))
			return (-1);
	}
	return (0);
}

long	ft_atoi(const char *string)
{
	int		sign;
	long	tmp;
	long	hold;

	sign = 1;
	tmp = 0;
	hold = 0;
	ft_check(&string, &sign);
	while (*string && ft_isdigit(*string))
	{
		tmp = *string - '0';
		if (overflow_check(sign, tmp, hold) == 1)
			return (LONG_MAX);
		if (overflow_check(sign, tmp, hold) == -1)
			return (LONG_MIN);
		hold = hold * 10 + tmp;
		string++;
	}
	return (sign * hold);
}

// #include <stdio.h>
// int	main(int ac,char *av[])
// {
// 	char	*ft_atoi_test;
// 	char	*atoi_test;

// 	if(ac > 1)
// 	{
// 		ft_atoi_test = av[1];
// 		atoi_test = av[1];
// 		printf("ft_atoi : %d\n" , ft_atoi(ft_atoi_test));
// 		printf("atoi    : %d\n" , atoi(atoi_test));
// 	}
// 	return (0);
// }
