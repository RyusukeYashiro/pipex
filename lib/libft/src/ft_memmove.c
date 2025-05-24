/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:35:25 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/30 16:27:28 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*hold;
	unsigned char	*s;

	if (len == 0 || (!dst && !src))
		return (dst);
	hold = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (hold < s)
	{
		while (len--)
			*hold++ = *s++;
	}
	else
	{
		s += len - 1;
		hold += len - 1;
		while (len--)
			*hold-- = *s--;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	dest1[15] = "abcdefg";
// 	char	dest2[15] = "abcdefg";

// 	memmove(&dest1[3], &dest1[0], 4);
// 	ft_memmove(&dest2[3], &dest2[0], 4);
// 	printf("Standard memmove: %s\n", dest1);
// 	printf("Custom ft_memmove: %s\n", dest2);
// 	return (0);
// }
