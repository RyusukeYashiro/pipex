/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:09:06 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/28 12:56:44 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*hold;

	i = 0;
	hold = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!hold)
		return (NULL);
	while (s1[i])
	{
		hold[i] = s1[i];
		i++;
	}
	hold[i] = '\0';
	return (hold);
}

// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	char	*p;
// 	char	*str;

// 	if (argc > 1)
// 	{
// 		str = argv[1];
// 		p = ft_strdup(str);
// 		printf("ft_strdup(p) = %s\n", p);
// 		free(p);
// 	}
// }
