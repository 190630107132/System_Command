#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("temp4.txt",O_CREAT | O_RDWR | O_EXCL,0666);
	if(fd == -1)
	{
		perror("\nOpening the file!!\n");
		return 1;
	}
	else
		printf("\nSUCESS...\n");
	printf("\nOutput: %d\n",fd);	
	return 0;
}
