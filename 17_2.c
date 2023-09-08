#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
int main()
{
	int fd = open("data.txt",O_RDWR);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
	printf("\nEnter number of tickets you want to book : ");
	int nt;
	scanf("%d",&nt);
	int data;
	char rd[5],wd[5];
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	printf("\nTrying to get lock.\n");
	if(fcntl(fd,F_SETLKW,&fl) == -1)
	{
		perror("fcntl");
		return 1;
	}
	printf("\nLock acquired.\n");
	int r = read(fd,rd,5);
	if(r != 0)
	data = atoi(rd);
	else
		data = 0;
	
	data += nt;	
	sprintf(wd,"%d",data);
	
	ftruncate(fd,5);
	lseek(fd,0,SEEK_SET);
	write(fd,wd,sizeof(wd));
	
	printf("\nData Updated!!\n");
	printf("\nNew Value is %s",wd);
	printf("\nPress Enter to unlock the file.\n");
	getchar();
	getchar();
	fl.l_type = F_UNLCK;
	if(fcntl(fd,F_SETLK,&fl) == -1)
	{
		perror("fcntl");
		return 1;
	}
	printf("\nFile Unlocked\n");
	close(fd);
	return 0;
}
