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

	printf("Enter the name of a file to check: \n");
	read = getline(&buffer,&buf_size,stdin);

	if(read <=0 ){
		printf("getline failed\n");
		exit(1);
	}

	if(buffer[read-1] == '\n'){
		buffer[read-1] = 0;
	}

	int s = open(buffer,O_RDONLY);
	if(s==-1){
		printf("File doesn't exist\n");
		exit(1);
	}
	else
	{
		sfile(buffer);
	}
	free(buffer);
	return 0;

	//pointer to stat structure
	//struct stat sfile;

	//stst system call
	//stat("/home/maharshi/Desktop/System Software/HandOnList_1",&sfile);

	//accessing st_mode ( daa member of stat struct )
	//printf("st_mode = %o",sfile.st_mode);
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
	printf("\nFile inode number : %ld",sfile.st_ino);
	printf("\nNumber of hard links: %ld",(unsigned int)sfile.st_nlink);
	printf("\nUID : %ld",sfile.st_uid);
	printf("\nGID : %ld",sfile.st_gid);
	printf("\nSize : %ld",sfile.st_size);
	printf("\nBlock size : %ld",sfile.st_blksize);
	printf("\nNumber of blocks : %ld",sfile.st_blocks);
	printf("\nTime of last acces : %s",formatdata(date,sfile.st_atime)); //st_atime
	printf("\nTime of last modification : %s",formatdata(date,sfile.st_ctime)); //st_ctime
	printf("\nTime of last change : %s",formatdata(date,sfile.st_mtime)); //st_mtime
	printf("\n");
}
