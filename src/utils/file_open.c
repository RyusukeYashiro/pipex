/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:50:51 by ryyashir          #+#    #+#             */
/*   Updated: 2025/06/28 19:55:05 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../lib/libft/include/libft.h"

int	ft_open(char *file, int file_type)
{
	int	fd;

	fd = 0;
	if (file_type == 0)
		fd = open(file, O_RDONLY);
	else if (file_type == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}
