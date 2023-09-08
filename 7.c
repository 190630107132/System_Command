#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc , char* argv[]) {
	
	if(argc != 3)
	{
		perror("Not proper input");
		return 1;	
	}
	int fd_read = open(argv[1],O_RDONLY);
	int fd_write = open(argv[2],O_WRONLY|O_CREAT,0666);
	if(fd_read == -1 || fd_write == -1)
	{
		perror("Opening the file!!");
		return 1;
	}
	
	while(1)
	{
		char buff;
		int char_read = read(fd_read,&buff,1);
		if(char_read == -1)
		{
			perror("Read");
			return 1;
		}
		if(char_read == 0)
			break;
		int char_written = write(fd_write,&buff,1);
		if(char_written == -1)
		{
			perror("Write");
			return 1;
		}
	}
	printf("\nCopy Successfull!!\n");
	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd_write);
	if(fd_read_close == -1 || fd_write_close == -1)
	{
		perror("Not able to close");
		return 1;
	}
	return 0;
}
