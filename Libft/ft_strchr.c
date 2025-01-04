/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:04:06 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/28 12:55:32 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 		const char *str = argv[1];
// 	int		c;
// 	char	*result;
// 	char	*test;

// 	if(argc > 2)
// 	{
// 		c = argv[2][0];
// 		result = ft_strchr(str,c);
// 		test = strchr(str, c);
// 		if (result) {
// 			printf("Characterc '%c' found at poscition: %ld\n", c, result - str
// 				+ 1);
// 			printf("Characterc '%c' found at poscition: %ld\n", c, test - str
// 				+ 1);
// 		} else {
// 			printf("Character '%c' not found in \"%s\"\n", c, str);
// 			}
// 	}
// 	return (0);
// }
