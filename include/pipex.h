/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:23:36 by ryusukeyash       #+#    #+#             */
/*   Updated: 2025/01/24 21:47:14 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>

# define CMD_ERR "command not found\n"
# define DIR_ERR "No such file or directory\n"
# define FILE_ERR_P "Permission denied"
# define FILE_ERR_N "No such file or directory\n"

typedef struct s_pipex
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	**cmd_split_in;
	char	*cmd_fullpath;
	char	**env_split;
	char	*file_name;
}			t_pipex;

char    *ft_execv_cmd(t_pipex *pipx, char *env[]);
void		ft_free_split(char **split);
void		ft_ac_check(int ac);
void		ft_child1(char *av[], t_pipex *pipex, char *env[]);
void		ft_child2(char *av[], t_pipex *pipex, char *env[]);
void	ft_errorDeal(t_pipex *pipex ,  char *errormsg);
void   ft_execv(char **cmd , char *env[] , t_pipex *pipex);
char		*get_env_value(const char *key, char *env[]);
int			ft_open(char *file, int file_type);
void		ft_free_split(char **split);
void		ft_dup2_error(char **cmd, int fd);
void 	ft_init_struct(t_pipex *pipex);
void 	ft_printf(const char *format, ...);
#endif