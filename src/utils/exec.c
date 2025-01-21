/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:38:19 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/21 18:20:29 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex infile "ls -l" "wc -l" outfile = < infile ls -l | wc -l > outfile
//  ./pipex infile "grep a1" "wc -w" outfile = < infile grep a1 | wc -w > outfile

#include "../../include/libft.h"
#include "../../include/pipex.h"

char	*get_env_value(const char *key , const char **env)
{
    //ここでやりたい処理は
    // env[0] = "PATH=/usr/local/bin:/usr/bin:/bin";env[1] = "USER=your_username";env[2] = "HOME=/home/your_usernam";
	int     i = 0;
    int     key_len = ft_strlen(key);
    while(env[i])
    {
        //strncmpで比較して、もし０なら同じなのでその場合はそのみつけた情報を返す
        if(ft_strncmp(env[i] , key , key_len) == 0 && env[i][key_len] == '=')
            return (env[i] + key_len + 1);
        i++;
    }
    return (NULL);
}

//PATH=/usr/local/bin:/usr/bin:/bin
// 上記の中のディレクトリ群からそれぞれ実行可能ファイルを探す
char 	*ft_execv_cmd(t_pipex pipx , const char **env)
{
	int		i;
	char 	*temp;

	i = 0;
	while(pipx.env_split[i])
	{
		temp = ft_strjoin(pipx.env_split[i] , "/");
		pipx.cmd_fullpath = ft_strjoin(temp , pipx.cmd_split_in[0]);
		free(temp);
		if(access(pipx.cmd_fullpath , X_OK) == 0)
		{
			if(execve(pipx.cmd_fullpath , pipx.cmd_split_in , env) == -1)
				ft_errorDeal(pipx , DIR_ERR);
		}
		else
			free(pipx.cmd_fullpath);
		pipx.cmd_fullpath = NULL;	
		i++;
	}
	return (NULL);
}

//  現在、"ls"  "-l"がcmd_split_inに入っている
void   ft_exec(t_pipex pipex , const char **env)
{
    // 1 : そのコマンドがenvディレクトリの中に存在するかどうかを探す
    // 2 : もしあるなら、そのコマンドのフルパスを取得してくる
    // 3 : あとはexecvにexecv("path" , "pipex.cmd_split_in" , NULL)を実行する
    char    *path_env;

    path_env = get_env_value("PATH" , env);
	if(path_env == NULL)
		ft_errorDeal(pipex , CMD_ERR);
	pipex.env_split = ft_split(path_env , ':');
	if(pipex.env_split == NULL)
		ft_errorDeal(pipex , "split error");
	if(ft_execv_cmd(pipex , env) == NULL)
		ft_errorDeal(pipex , CMD_ERR);
}