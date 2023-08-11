#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("temp4.txt",O_CREAT|O_EXCL,0777);
	printf("Output: %d\n",fd);
	if(fd == -1)
		printf("Failed!!\n");
	else
		printf("SUCESS\n");
}
