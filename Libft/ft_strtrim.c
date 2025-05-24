/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:59:23 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/02 12:55:47 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*hold;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	hold = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!hold)
		return (NULL);
	ft_strlcpy(hold, &s1[start], end - start + 2);
	return (hold);
}
/*
#include <stdio.h>

 int	main(void)
 {
	char	*test;
	char	*st;
	char	*ans;

	test = "";
	st = "1234";
	ans = ft_strtrim(test, st);
	if (ans != NULL)
	{
		printf("%s", ans);
	}
 }
*/
