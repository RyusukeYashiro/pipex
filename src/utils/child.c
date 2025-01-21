/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:05 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/21 19:18:41 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile


void    ft_child1(const char **av , t_pipex pipex, char **env)
{
    int     fd;
	int		file_type;

	file_type = 0;
	pipex.file_name = av[2];
    char    **cmd1 = ft_split(pipex.file_name , " ");
    //infileを開く。つまり蛇口を開く
    fd = ft_open(av[1] , file_type);
	if(fd == -1 && file_type == 0)
	{
		ft_free_split(cmd1);
		ft_errorDeal(pipex , FILE_ERR_N);
	}
    //標準入力をファイルのファイルディスクリプタリダイレクト
    dup2(fd , 0);
    //標準出力をpipe_fd[1]、つまり書き込みエンドにリダイレクト
    dup2(pipex.pipefd[1] , 1);
    //不要な読み込みエンドは閉じる
    close(pipex.pipefd[0]);
    //実際にコマンド実行するための関数
    ft_execv(cmd1, env);
	ft_free_split(cmd1);
}

void    ft_child2(const char **av , t_pipex pipex , char **env)
{
    int		fd;
    char	**cmd2 = ft_split(av[3] , " ");
	int		file_type;
	
	file_type = 1;
	pipex.file_name = av[4];
    fd = ft_open(pipex.file_name , file_type);
	if(fd == -1 && file_type == 1)
	{
		ft_free_split(cmd2);
		ft_errorDeal(pipex , FILE_ERR_P);	
	}
    //標準入力をパイプの読み取りエンドにリダイレクト
    dup2(pipex.pipefd[0] , 0);
    // 標準出力を出力ファイルディスクリプタにリダイレクト
    dup2(fd , 1);
    close(pipex.pipefd[1]);
    ft_execv(cmd2 , env);
	ft_free_split(cmd2);
}