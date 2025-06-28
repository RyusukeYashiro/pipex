/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:59:49 by ryusukeyash       #+#    #+#             */
/*   Updated: 2025/06/28 22:32:02 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	ft_close_pipeend(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

void	ft_init_struct(t_pipex *pipex)
{
	pipex->file_name = NULL;
	pipex->cmd_fullpath = NULL;
	pipex->env_split = NULL;
	pipex->cmd_split_in = NULL;
}

static void	run_pipex(char *av[], char *env[], t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		perror("pipe");
		exit(1);
	}
	if (pipex->pid1 == 0)
	{
		ft_child1(av, pipex, env);
		exit(0);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
	{
		perror("pipe");
		exit(1);
	}
	if (pipex->pid2 == 0)
	{
		ft_child2(av, pipex, env);
		exit(0);
	}
}

int	main(int ac, char *av[], char *env[])
{
	t_pipex	pipex;

	ft_ac_check(ac);
	ft_init_struct(&pipex);
	if (pipe(pipex.pipefd) < 0)
		return (perror("pipe"), 1);
	run_pipex(av, env, &pipex);
	ft_close_pipeend(pipex.pipefd);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
