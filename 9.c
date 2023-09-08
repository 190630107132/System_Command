#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

void sfile(char const fileName[]);
char *formatdata(char * str , time_t val);
int main()
{
	ssize_t read;
	char* buffer = 0;
	size_t buf_size = 0;

	printf("\nEnter the name of a file to check: \n");
	read = getline(&buffer,&buf_size,stdin);

	if(read <=0 ){
		perror("getline failed\n");
		return 1;
	}

	if(buffer[read-1] == '\n'){
		buffer[read-1] = 0;
	}

	int fd = open(buffer,O_RDONLY);
	if(fd == -1)
	{
		perror("File doesn't exist\n");
		return 1;
	}
	else
	{
		sfile(buffer);
	}
	free(buffer);
	return 0;
}

char * formatdata(char *str, time_t val){
	strftime(str,36,"%d.%m.%Y %H:%M:%S",localtime(&val));
	return str;
}

void sfile(char const fileName[]){
	struct stat sfile;
	if(stat(fileName,&sfile)==-1){
		printf("Error Occured\n");
	}

	char date[36];
	// Accessing data mumber of stat struct
	printf("\nFile inode number : %lu",sfile.st_ino);
	printf("\nNumber of hard links: %lu",sfile.st_nlink);
	printf("\nUID : %u",sfile.st_uid);
	printf("\nGID : %u",sfile.st_gid);
	printf("\nSize : %ld",sfile.st_size);
	printf("\nBlock size : %ld",sfile.st_blksize);
	printf("\nNumber of blocks : %ld",sfile.st_blocks);
	printf("\nTime of last acces : %s",formatdata(date,sfile.st_atime)); //st_atime
	printf("\nTime of last modification : %s",formatdata(date,sfile.st_mtime)); //st_mtime
	printf("\nTime of last change : %s",formatdata(date,sfile.st_ctime)); //st_ctime
	printf("\n");
}
