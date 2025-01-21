#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>

# define CMD_ERR "Command not found"
# define DIR_ERR "No such file or directory"
# define FILE_ERR_P "Permission denied"
# define FILE_ERR_N "No such file or directory"


typedef struct s_pipex
{
    int     pipefd[2];
    pid_t   pid1;
    pid_t   pid2;
    int     infile;
    int     outfile;
    char   **cmd_split_in;
    char   **cmd_fullpath;
    char    **env_split;
	char	*file_name;
} t_pipex;

void	ft_errorDeal(t_pipex pipex ,  const *errormsg);
char 	*ft_execv_cmd(t_pipex pipx , const char **env);
void	ft_free_split(char **split);
#endif