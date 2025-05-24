/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errordeal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:21:47 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/24 22:47:39 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/include/libft.h"
#include "../../include/pipex.h"

void	ft_errorDeal(t_pipex *pipex ,  char *errormsg)
{
	ft_putstr_fd("bash: ", 2);
	if (ft_strncmp(errormsg, CMD_ERR, ft_strlen(CMD_ERR)) == 0)
	{
    	ft_putstr_fd(pipex->cmd_split_in[0], 2);
		if(pipex->cmd_split_in[0])
			ft_putstr_fd(": " , 2);
    	ft_putstr_fd(errormsg , 2);
	}
	else if (ft_strncmp(errormsg, FILE_ERR_P, ft_strlen(FILE_ERR_P)) == 0 || ft_strncmp(errormsg, FILE_ERR_N, ft_strlen(FILE_ERR_N)) == 0)
		ft_printf("%s: %s\n", pipex->file_name, errormsg);	
	else if (ft_strncmp(errormsg, DIR_ERR, ft_strlen(DIR_ERR)) == 0)
		ft_printf("%s: %s\n", pipex->cmd_fullpath, errormsg);
	else
		ft_printf("%s\n", errormsg);
	if(pipex->env_split)
	{
		ft_free_split(pipex->env_split);
		pipex->env_split = NULL;
	}
	if(pipex->cmd_fullpath)
	{
		free(pipex->cmd_fullpath);
		pipex->cmd_fullpath = NULL;
	}
	exit(1);
}

void	ft_dup2_error(char **cmd , int fd)
{
	perror("Error");
	ft_free_split(cmd);
	close(fd);
	exit(EXIT_FAILURE);
}