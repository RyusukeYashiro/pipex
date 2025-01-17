#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


typedef struct s_pipex
{
    int     pipefd[2];
    pid_t   pid1;
    pid_t   pid2;
    int     infile;
    int     outfile;
    const   **cmd_av;
} t_pipex;


#endif
