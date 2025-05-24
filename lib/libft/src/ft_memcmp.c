/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:05:58 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/26 02:53:11 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t				i;
	const unsigned char	*hold1;
	const unsigned char	*hold2;

	i = 0;
	hold1 = (const unsigned char *)buf1;
	hold2 = (const unsigned char *)buf2;
	while (i < n)
	{
		if (hold1[i] != hold2[i])
		{
			return (hold1[i] - hold2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	char buf1[] = "abcdef";
	char buf2[] = "abcguh";
	size_t len = 3;
	size_t len2 = 4;

	printf("ft_memcmp_test1 = %d\n ", ft_memcmp(buf1, buf2, len));
	printf("memcmp_test2 = %d\n ", memcmp(buf1, buf2, len));

	printf("ft_memcmp_test1 = %d\n ", ft_memcmp(buf1, buf2, len2));
	printf("memcmp_test2 = %d\n ", memcmp(buf1, buf2, len2));
	return (0);
}
*/
