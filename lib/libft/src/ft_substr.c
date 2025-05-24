/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:40:57 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/02 00:51:37 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*hold;
	char const	*start_s;
	size_t		s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	hold = (char *)malloc(len + 1);
	if (!hold)
		return (NULL);
	start_s = &s[start];
	ft_strlcpy(hold, start_s, len + 1);
	return (hold);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "substr function Implementation";
// 	int		st;
// 	int		en;
// 	char	*ft_test;

// 	st = 7;
// 	en = 9;
// 	ft_test = ft_substr(src, st, en);
// 	printf("%s\n", ft_test);
// 	return (0);
// }
