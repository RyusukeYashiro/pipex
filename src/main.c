/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:59:49 by ryusukeyash       #+#    #+#             */
/*   Updated: 2025/01/22 21:54:31 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  < file1 cmd1 | cmd2 > file2

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile

#include "libft.h"
#include "pipex.h"


void ft_close_pipeend(int pipefd[2])
{
    close(pipefd[0]);
    close(pipefd[1]);
}

void 	ft_init_struct(t_pipex *pipex)
{
	pipex->file_name = NULL;
    pipex->cmd_fullpath = NULL;
    pipex->env_split = NULL;
    pipex->cmd_split_in = NULL;
}

int main(int ac , char *av[]  , char *env[])
{
    t_pipex pipex;
    //引数をチェックする関数
    ft_ac_check(ac);
	ft_init_struct(&pipex);
    // パイプの作成
    if(pipe(pipex.pipefd) < 0)
        return(perror("pipe") , 1);
    //最初の子プロセス１を作成
    pipex.pid1 = fork();
    if(pipex.pid1 < 0)
        return(perror("pipe") , 1);
    if(pipex.pid1 == 0)
    {
        ft_child1(av , &pipex , env);
        exit(0);
    }
    pipex.pid2 = fork();
    if(pipex.pid2 < 0)
        return(perror("pipe") , 1);
    if(pipex.pid2 == 0)
    {
        ft_child2(av , &pipex , env);
        exit(0);
    }
    ft_close_pipeend(pipex.pipefd);
    //親プロセスがwaitpidを使用して、子プロセスの終了をキャッチ
    // ゾンビプロセスは親プロセスが子プロセスの終了ステータスを収集することで解消できます。
    waitpid(pipex.pid1 , NULL , 0);
    waitpid(pipex.pid2 , NULL , 0);
    return (0);
}