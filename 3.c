#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd = creat("temp3.txt",0666);
	if(fd == -1)
	{
		perror("creat");
		return 1;
	}
	printf("\nFile Descriptor Value : %d.\n",fd);
	return 0;	
}
