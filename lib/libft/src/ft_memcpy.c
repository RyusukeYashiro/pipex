/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:56:00 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/30 14:11:23 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*hold;
	unsigned char	*s;
	size_t			i;

	hold = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!hold && !s)
		return (0);
	i = 0;
	while (i < n)
	{
		hold[i] = s[i];
		i++;
	}
	return (hold);
}

/*
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char	src[] = "";
	char	dest1[50];
	char	dest2[50];

	ft_memcpy(dest1, src, sizeof(src));
	memcpy(dest2, src, sizeof(src));
	printf("Original memcpy: %s\n", dest2);
	printf("Custom ft_memcpy: %s\n", dest1);
	return (0);
}
*/
