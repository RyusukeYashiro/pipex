/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:37 by ryyashir          #+#    #+#             */
/*   Updated: 2024/12/31 20:42:45 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile


#include "../../include/libft.h"
#include "../../include/pipex.h"

void    ft_parent(int **av , int **p_fd, char **env)
{
    int     fd;

    fd = ft_open(av);
    dup2(fd , 1);
    close(fd);
    ft_exec()

}