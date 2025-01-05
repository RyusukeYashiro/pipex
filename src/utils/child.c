/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:05 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/05 19:39:10 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile


void    ft_child(const char **av , int **pid_fd, char **env)
{
    int     fd;

    //infileを開く。つまり蛇口を開く
    fd = ft_open(av , 0);
    // キーボードからの入力つまり標準入力をファイルのディスクリプタにすることでファイルの中身を読み取る
    dup2(fd, 0);
    // 標準出力がパイプの書き込みエンドに接続させる。つまり子プロセスが生成した出力データをパイプに流す
    dup2(pid_fd[1] , 1);
    close(pid_fd[0]);
    ft_execv(av[2] , env);
}