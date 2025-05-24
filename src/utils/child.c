/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:05 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/23 04:09:03 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/include/libft.h"
	#include "../../include/pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile
// wc-l: Command not found


void    ft_child1(char *av[] , t_pipex *pipex, char *env[])
{
    int     fd;
	int		file_type;
	char    **cmd1;	

	file_type = 0;
	pipex->file_name = av[1];
	cmd1 = ft_split(av[2] , ' ');
    //infileを開く。つまり蛇口を開く
    fd = ft_open(pipex->file_name , file_type);
	if(fd == -1 && file_type == 0)
	{
		ft_free_split(cmd1);	
		ft_errorDeal(pipex , FILE_ERR_N);
	}
    //標準入力をファイルのファイルディスクリプタリダイレクト
    if(dup2(fd , 0) == -1)
		ft_dup2_error(cmd1 , fd);
    //標準出力をpipe_fd[1]、つまり書き込みエンドにリダイレクト
    if(dup2(pipex->pipefd[1] , 1) == -1)
		ft_dup2_error(cmd1 , fd);
    //不要な読み込みエンドは閉じる
    close(pipex->pipefd[0]);
    //実際にコマンド実行するための関数	
    ft_execv(cmd1, env , pipex);
	ft_free_split(cmd1);
}

void    ft_child2(char *av[] , t_pipex *pipex , char *env[])
{
    int		fd;
	int		file_type;
    char	**cmd2;
	
	file_type = 1;
	pipex->file_name = av[4];
	cmd2 = ft_split(av[3] , ' ');
	// プロセスがファイルやパイプを開いた際に、割り振られるのがfd
    fd = ft_open(pipex->file_name , file_type);
	if(fd == -1 && file_type == 1)
	{
		ft_free_split(cmd2);
		ft_errorDeal(pipex , FILE_ERR_P);	
	}
    //標準入力をパイプの読み取りエンドにリダイレクト
	if(dup2(pipex->pipefd[0] , 0) == -1)
		ft_dup2_error(cmd2 , fd);
    // 標準出力を出力ファイルディスクリプタにリダイレクト
    dup2(fd , 1);
    close(pipex->pipefd[1]);
    ft_execv(cmd2 , env , pipex);
	ft_free_split(cmd2);
}