#include <unistd.h>
#include <stdio.h>


//int access(const char *filePath , int mode)

int main(void)
{
	if(access("./tesi8989t" , R_OK)==0)
	{
		printf("this is RorX ok");
		return(0);
	}
	printf("this is not RorX ok");
}