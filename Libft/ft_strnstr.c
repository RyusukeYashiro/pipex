/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:56:33 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/30 15:48:31 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && !len)
		return (NULL);
	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			if (i + j >= len)
				break ;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void) {
// 	const char *haystack = "abbbcdefg";
// 	const char *needle = "bbc";
// 	size_t len = 20;

// 	const char *test = ft_strnstr(haystack,needle,len);
// 	if (test) {
// 		printf("Found: '%s'\n",test);
// 	}
// 	return (0);
// }