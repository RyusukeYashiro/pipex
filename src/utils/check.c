/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:20:00 by ryyashir          #+#    #+#             */
/*   Updated: 2024/12/31 15:40:50 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"


void   ft_ac_check(int ac)
{
    if (ac != 5)
    {
        ft_putstr_fd("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 2);
        exit(1);
    }
}