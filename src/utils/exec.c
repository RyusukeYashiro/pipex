/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:38:19 by ryyashir          #+#    #+#             */
/*   Updated: 2025/06/28 22:58:10 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../lib/libft/include/libft.h"

char	*get_env_value(const char *key, char *env[])
{
	int	i;
	int	key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=')
			return (env[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

char	*ft_execv_cmd(t_pipex *pipx, char *env[])
{
	int		i;
	char	*temp;

	i = 0;
	while (pipx->env_split[i])
	{
		temp = ft_strjoin(pipx->env_split[i], "/");
		pipx->cmd_fullpath = ft_strjoin(temp, pipx->cmd_split_in[0]);
		free(temp);
		if (access(pipx->cmd_fullpath, X_OK) == 0)
		{
			if (execve(pipx->cmd_fullpath, pipx->cmd_split_in, env) == -1)
				ft_errordeal(pipx, DIR_ERR);
		}
		else
			free(pipx->cmd_fullpath);
		pipx->cmd_fullpath = NULL;
		i++;
	}
	return (NULL);
}

void	ft_execv(char **cmd, char *env[], t_pipex *pipex)
{
	char	*path_env;

	pipex->cmd_split_in = cmd;
	path_env = get_env_value("PATH", env);
	if (path_env == NULL)
		ft_errordeal(pipex, CMD_ERR);
	pipex->env_split = ft_split(path_env, ':');
	if (pipex->env_split == NULL)
		ft_errordeal(pipex, "split error");
	if (ft_execv_cmd(pipex, env) == NULL)
		ft_errordeal(pipex, CMD_ERR);
}
