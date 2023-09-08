#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	struct flock fl;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();

	int fd;
	printf("\nLock for:\n1.Read\n2.Write\nEnter your choice (1 or 2): ");
	int choice;
	scanf(" %d",&choice);
	switch (choice)
	{
		case	1	:	fl.l_type = F_RDLCK;
		break;
		case	2	:	fl.l_type = F_WRLCK;
		break;
	}
	
	fd = open("temp.txt",O_RDWR);
	
	if(fd == -1)
	{
		perror("Open");
		return 1;
	}

	printf("\nPress Enter to get lock.\n");
	getchar();
	printf("\nTrying to get lock...\n");

	if(fcntl(fd,F_SETLKW,&fl) == -1)
	{
		perror("fcntl");
		return 1;
	}

	printf("\nLocak aquired!!\n");
	printf("\nPress Enter to release lock.\n");
	getchar();

	fl.l_type = F_UNLCK;

	if(fcntl(fd,F_SETLK,&fl) == -1)
	{
		perror("fcntl");
		return 1;
	}
	printf("\nLock released!!\n");
	if(close(fd) == -1)
	{
		perror("Close");
		return 1;
	}
	return 0;
}	
