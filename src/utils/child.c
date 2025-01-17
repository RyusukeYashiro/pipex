/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:05 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/17 20:37:47 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile


void    ft_child1(const char **av , int **pid_fd, char **env)
{
    t_pipex pipex;
    int     fd;
    
    //infileを開く。つまり蛇口を開く
    fd = ft_open(av[1]);
    //標準入力をファイルのファイルディスクリプタリダイレクト
    dup2(fd , 0);
    //標準出力をpipe_fd[1]、つまり書き込みエンドにリダイレクト
    dup2(pid_fd[1] , 1);
    //不要な読み込みエンドは閉じる
    close(pid_fd[0]);
    //実際にコマンド実行するための関数
    ft_execv(av , env);
}

void    ft_child2(const char **av , int **pid_fd , char **env)
{
    t_pipex     pipex;
    int         fd;

    fd = ft_open(av[4]);
    //標準入力をパイプの読み取りエンドにリダイレクト
    dup2(pid_fd[0] , 0);
    // 標準出力を出力ファイルディスクリプタにリダイレクト
    dup2(fd , 1);
    close(pid_fd[1]);
    ft_execv(av , env);
}