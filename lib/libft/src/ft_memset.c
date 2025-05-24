/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:55:30 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/30 14:04:04 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*hold;

	hold = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		hold[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	buf[6] = "heo";
// 	char	test_buf[6] = "heo";

// 	// char buf2[5];
// 	// char test_buf2[10];
// 	memset(test_buf, '#', 5);
// 	ft_memset(buf, '#', 5);
// 	printf("ft_memset = %s\n", buf);
// 	printf("memset = %s\n", test_buf);
// }
