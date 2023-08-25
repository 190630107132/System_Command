#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("temp.txt",O_RDWR|O_APPEND);
	int flag = fcntl(fd,F_GETFL);
	if(flags==-1)
		exit(1);
	printf("Get file descriptor flags (F_GETFD) %d\n",flag);
	return 0;
}
