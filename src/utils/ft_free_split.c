/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:49:58 by ryusukeyash       #+#    #+#             */
/*   Updated: 2025/01/22 19:52:30 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"

void	ft_free_split(char **split)
{
	int 	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);	
}