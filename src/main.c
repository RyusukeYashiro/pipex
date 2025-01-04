/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:59:49 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/31 18:56:51 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  < file1 cmd1 | cmd2 > file2

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile

#include "../include/libft.h"
#include "../include/pipex.h"

int main(int ac , char *av[]  , char **env)
{
    int     pipefd[2];
    pid_t   pid;

    ft_ac_check(ac);
    if(pipe(pipefd) < 0)
    {
        perror("pipe");
        return (1);
    }
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return (1);
    }
    if(pid == 0)
    {
        ft_child(av , pipefd , env);
    } else {
        ft_parent(av , pipefd , env);
    }
}