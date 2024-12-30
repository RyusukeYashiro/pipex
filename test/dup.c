#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// dup() は、ファイル記述子 oldfd の複製を作成し、最も小さい未使用のファイル記述子を返す
// dup2() は、基本は dup() と同じですが、newfd で指定した番号のファイル記述子を返す
// 既に open しているファイル記述子を指定した場合は、元の記述子は自動的に close される。

// int dup2(int oldfd , int newfd);

int main(){
	int file_desc = open("test.txt" , O_WRONLY | O_APPEND);
	if(file_desc < 0)
	{
		printf("ファイルを開くのに失敗しました");
		return (-1);
	}

	int new_desc = dup(file_desc);
	if(new_desc < 0)
	{
		printf("ファイルの複製に失敗しました");
		return (-1);
	}

	write(new_desc , "Hello world!" , 13);
	close(file_desc);
	close(new_desc);

	return(0);
}