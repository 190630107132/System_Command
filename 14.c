#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	if(argc !=2)
	{
		perror("Give proper input!!");
		return 1;
	}

	const char* filename=argv[1];

	struct stat stt;
	if(stat(filename, &stt)==-1)
	{
		perror("Unable to get file information");
		return 1;
	}

	if(S_ISREG(stt.st_mode))
	{
		printf("%s is a regular file. \n", filename);
	}else 
	if (S_ISDIR(stt.st_mode))
	{
		printf("%s is a directory.\n", filename);
	}else 
	if(S_ISLNK(stt.st_mode))
	{
		printf("%s is a symbolic link.\n", filename);
	}else
	if(S_ISFIFO(stt.st_mode))
	{
		printf("%s is a FIFO/pipe.\n", filename);
	}else 
	if(S_ISSOCK(stt.st_mode))
	{
		printf("%s is a socket.\n", filename);
	}else 
	if(S_ISBLK(stt.st_mode))
	{
		printf("%s is a block special file.\n" , filename);
	}else 
	if(S_ISCHR(stt.st_mode))
	{
		printf("%s is a charcter special file.\n" , filename);
	}else
	{
		printf("%s is of an unknown type.\n" , filename);
	}
	return 0;
}

