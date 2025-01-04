/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:43:29 by ryyashir          #+#    #+#             */
/*   Updated: 2024/05/04 14:39:09 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	count_len(char const **s, char c)
{
	int	len;

	len = 0;
	while (**s != c && **s)
	{
		(*s)++;
		len++;
	}
	return (len);
}

static void	ft_free(char **hold, int count)
{
	while (count > 0)
	{
		free(hold[count - 1]);
		count--;
	}
	free(hold);
}

static char	*ft_dup(const char *s, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**hold;
	int		count_word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count_word = count_words(s, c);
	hold = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!hold)
		return (NULL);
	while (i < count_word)
	{
		while (*s && (*s == c))
			s++;
		hold[i] = ft_dup(s, count_len(&s, c));
		if (!hold[i])
		{
			ft_free(hold, i);
			return (NULL);
		}
		i++;
	}
	hold[count_word] = NULL;
	return (hold);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	char	charSet;
// 	char	**split_Result;

// 	str = "aabc\0cbeeb";
// 	charSet = 'b';
// 	split_Result = ft_split(str, charSet);
// 	if (split_Result)
// 	{
// 		for (int i = 0; split_Result[i]; i++)
// 		{
// 			printf("%s\n", split_Result[i]);
// 			free(split_Result[i]);
// 		}
// 		free(split_Result);
// 	}
// 	return (0);
// }
