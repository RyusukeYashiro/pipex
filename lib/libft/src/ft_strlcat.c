/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:16:00 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/04/30 16:18:49 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dst && !dstsize)
		return (dstsize + src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	while (i < dstsize - 1 && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char dst[256] = "\0";
// 	const char *src = "huhu";
// 	size_t dstsize = 0;
// 	size_t result;

// 	result = strlcat(dst, src, dstsize);
// 	printf("After ft_strlcat: \"%s\", Length: %zu\n", dst, result);

// 	// result = strlcat(dst, src, dstsize);
// 	// printf("After standard strlcat: \"%s\", Length: %zu\n", dst, result);
// 	return (0);
// }
