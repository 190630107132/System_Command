#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/types.h>

int main()
{
	
	fd_set readfds;
	
	struct timeval timeout;
	
	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	
	timeout.tv_sec=10;
	timeout.tv_usec=0;
	
	int rselect=select(0+1,&readfds,NULL,NULL,&timeout);
	
	if(rselect == -1)
	{
		perror("Select");
		return 1;
	}else 
	if(rselect == 0)
	{
		printf("Data not available\n");
		return 1;
	}

	if(FD_ISSET(0,&readfds))
	{
		char buff[1024];
		int len;

		len = read(0,buff,1024);
		if(len == -1)
		{
			perror("read");
			return 1;
		}
		if(len)
		{
			buff[len] = '\0';
			printf("\nRead data : %s\n",buff);
		}
	}
	return 0;
}
