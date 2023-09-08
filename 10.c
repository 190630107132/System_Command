#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("temp.txt",O_RDWR);
	if(fd == -1)
	{
		perror("Opening file!!");
		return 1;
	}
	char str[21] = "1234567890ABCDEFGHIJ";
	write(fd,str,10);
	lseek(fd,10,SEEK_CUR);
	write(fd,&str[10],10);
	printf("\n File after operation:\n");
	system("od -c temp.txt");
	return 0;
}
