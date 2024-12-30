#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// $ echo "Hello World!" > test.txt

int main(void){
	int fd;
	char *av[3];
	extern char **environ;

	//リダイレクト先のファイルを用意。
	fd = open("test.txt" , O_WRONLY | O_APPEND) ;
	if(fd < 0) {
		perror("open");
		return (-1);
	}

	//標準出力を割り当てる
	if(dup2(fd , 1) < 0){
		perror("dup2");
		close(fd);
		return (-1);
	}

	close(fd);

	av[0] = "echo";
	av[1] = "Hello wold!";
	av[2] = NULL;
	execve("/bin/echo" , av , environ);
	perror("execve");
	return (-1);
}