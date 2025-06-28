/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:20:00 by ryyashir          #+#    #+#             */
/*   Updated: 2025/06/28 19:47:25 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../lib/libft/include/libft.h"

void	ft_ac_check(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 2);
		exit(1);
	}
}
