#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd = creat("temp3.txt",0777);
	printf("File Descriptor Value : %d.\n",fd);
	return 0;	
}
