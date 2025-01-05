/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:37 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/05 19:39:01 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile

#include "../../include/libft.h"
#include "../../include/pipex.h"

// 子プロセスの出力 -> パイプ->  親プロセス（標準入力

void    ft_parent(const char **av , int **pid_fd, char **env)
{
    int     fd;

    //infileを開く。つまり蛇口を開く
    fd = ft_open(av[4] , 1);
    // これ以降このプロセスの標準出力に書き込まれるデータはすべて上記のopenしたファイルに書き込まれるようになる
    dup2(fd , 1);
    // 親プロセスの標準入力がパイプの読み取りエンドに接続される
    dup2(pid_fd[0] , 0);
    // ここのプロセスは読み込む用（データの受取）なので書き込みエンドは不要になる
    close(pid_fd[1]);
    ft_exec(av[4] , env);
}