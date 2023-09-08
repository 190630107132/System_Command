#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int fd = open("temp.txt",O_RDWR);
	if(fd == -1)
	{
		perror("Error opening the file\n");
		return 1;
	}
	int copy_fd = dup(fd);
	write(fd,"This is from fd\n",strlen("This is from fd\n"));
	write(copy_fd,"This is from copy_fd\n",strlen("This is from copy_fd\n"));
	int dup_2 = dup2(fd,3);
	write(dup_2,"This is from dup_2\n",strlen("This is from dup_2\n"));
	int fcntl_dup = fcntl(fd,F_DUPFD);
	write(fcntl_dup,"This is from fcntl_dup\n",strlen("This is from fcntl_dup\n"));
	
	return 0;
}
