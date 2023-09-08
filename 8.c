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
		perror("\nUnable to open the file\n");
		return 1;
	}

	while(1)
	{
		char ch;
		int read_data = read(fd_read,&ch,1);
		if(read_data == -1)
		{
			perror("Read");
			return 1;
		}
		if(read_data == 0)
			break;
		if(ch == '\n')
		{
			write(1,"\n\n",sizeof("\n\n"));
		}
		else
		write(1,&ch,1);
	}
	int fd_close = close(fd_read);
	if(fd_close == -1)
	{
		perror("\nClosing the file\n");
		return 1;
	}
	return 0;
}
