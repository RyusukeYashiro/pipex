/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errordeal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:21:47 by ryyashir          #+#    #+#             */
/*   Updated: 2025/01/21 19:14:13 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/pipex.h"

void	ft_errorDeal(t_pipex pipex ,  const char *errormsg)
{
	int		i;

	i = 0;
	//error出力の処理
	if (ft_strncmp(errormsg, CMD_ERR, ft_strlen(CMD_ERR)) == 0)
		ft_printf("%s: %s\n", pipex.cmd_split_in[0], errormsg);
	else if (ft_strncmp(errormsg, DIR_ERR, ft_strlen(DIR_ERR)) == 0)
		ft_printf("%s: %s\n", pipex.cmd_fullpath, errormsg);
	else if (ft_strncmp(errormsg, FILE_ERR_P, ft_strlen(FILE_ERR_P)) == 0 || ft_strncmp(errormsg, FILE_ERR_N, ft_strlen(FILE_ERR_N)) == 0)
		ft_printf("%s: %s\n", pipex.file_name, errormsg);
	else
		ft_printf("%s\n", errormsg);
	if(pipex.env_split)
		ft_free_split(pipex.env_split);
	if(pipex.cmd_fullpath)
		free(pipex.cmd_fullpath);

	exit(1);
}