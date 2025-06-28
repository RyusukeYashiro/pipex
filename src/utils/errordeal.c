/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errordeal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:21:47 by ryyashir          #+#    #+#             */
/*   Updated: 2025/06/28 23:00:40 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../lib/libft/include/libft.h"

void	ft_dup2_error(char **cmd, int fd)
{
	if (cmd)
		ft_free_split(cmd);
	if (fd > 0)
		close(fd);
	perror("dup2");
	exit(1);
}

static void	print_cmd_err(t_pipex *pipex, char *errormsg)
{
	ft_putstr_fd(pipex->cmd_split_in[0], 2);
	if (pipex->cmd_split_in[0])
		ft_putstr_fd(": ", 2);
	ft_putstr_fd(errormsg, 2);
}

static void	free_and_exit(t_pipex *pipex)
{
	if (pipex->env_split)
		ft_free_split(pipex->env_split);
	if (pipex->cmd_fullpath)
		free(pipex->cmd_fullpath);
	exit(1);
}

void	ft_errordeal(t_pipex *pipex, char *errormsg)
{
	ft_putstr_fd("bash: ", 2);
	if (ft_strncmp(errormsg, CMD_ERR, ft_strlen(CMD_ERR)) == 0)
		print_cmd_err(pipex, errormsg);
	else if (ft_strncmp(errormsg, FILE_ERR_P, ft_strlen(FILE_ERR_P)) == 0
		|| ft_strncmp(errormsg, FILE_ERR_N, ft_strlen(FILE_ERR_N)) == 0)
		ft_printf("%s: %s\n", pipex->file_name, errormsg);
	else if (ft_strncmp(errormsg, DIR_ERR, ft_strlen(DIR_ERR)) == 0)
		ft_printf("%s: %s\n", pipex->cmd_fullpath, errormsg);
	else
		ft_printf("%s\n", errormsg);
	free_and_exit(pipex);
}
