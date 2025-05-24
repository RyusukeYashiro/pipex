/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:05:28 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/04 14:39:26 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cat(char *hold, const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		hold[i] = string[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*hold;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	hold = (char *)malloc(sizeof(char) * len + 1);
	if (!hold)
		return (NULL);
	ft_cat(hold, s1);
	ft_cat(hold + ft_strlen(s1), s2);
	hold[len] = '\0';
	return (hold);
}
/*
int	main(int ac, char *av[])
{
	char	*s1;
	char	*s2;
	char	*ft;

	if (ac > 2)
	{
		s1 = av[1];
		s2 = av[2];
		ft = ft_strjoin(s1, s2);
		printf("ft_strjoin = %s\n", ft);
	}
}
*/
