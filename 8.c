#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd_read = open("temp.txt",O_RDONLY);
	if(fd_read == -1)
	{
		printf("Unable to open the file\n");
		return 0;
	}

	while(1)
	{
		char ch;
		int read_data = read(fd_read,&ch,1);
		if(read_data == 0)
			break;
		if(ch == "\n")
			printf("\n");
	}
	int fd_close = close(fd_read);
	return 0;
}
