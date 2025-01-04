/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:14:09 by ryyashir          #+#    #+#             */
/*   Updated: 2024/04/26 02:50:43 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if(argc > 0)
	{
		printf("resutt = %zu\n" , ft_strlen(argv[1]));
		printf("test = %zu\n", strlen(argv[1]));
	}
	else
	{
		printf("this is error");
	}
}
*/
