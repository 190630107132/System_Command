#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("22.txt",O_RDWR | O_CREAT | O_TRUNC , 0666);
	if(fd == -1)
	{
		perror("File opening\n");
		return 1;
	}
	if(!fork())
	{
		write(fd,"Hello from child!!\n",sizeof("Hello from child!!\n"));
	}
	else
	{
		write(fd,"Hello from Parent !! \n",sizeof("Hello from Parent !! \n"));
	}
	return 0;
}
