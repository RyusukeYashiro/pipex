/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:01:03 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/01 16:13:19 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*hold;

	hold = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		if (*hold == (unsigned char)ch)
			return ((void *)hold);
		hold++;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	buf1[] = "A\0DE5FGH";
// 	char	buf2[] = "A\0CDE5FGH";
// 	char	*ft;
// 	char	*mem;

// 	ft = ft_memchr(buf1, '5', sizeof(buf1));
// 	mem = memchr(buf2, '5', sizeof(buf2));
// 	printf("ft_memchr = %s\n", ft);
// 	printf("memchr = %s\n", mem);
// }
