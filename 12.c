#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int fd = open("temp.txt",O_RDONLY);
	if(fd == -1)
	{
		perror("Opening file!");
		return 1;
	}
	int flag = fcntl(fd,F_GETFL);
	if(flag==-1)
	{
		perror("FCNTL command!");
		return 1;
	}
	switch(O_ACCMODE & flag)
	{
		case O_RDONLY: printf("\nFile is open in READ ONLY mode.\n");
		break;
		case O_WRONLY: printf("\nFile is open in WRITE ONLY mode.\n");
		break;
		case O_RDWR: printf("\nFile is open in READ WRITE mode.\n");
		break;
	}
	return 0;
}
