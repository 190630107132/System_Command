#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4,fd5; 
	fd1 = creat("5temp1.txt",0666);
	fd2 = creat("5temp2.txt",0666);
	fd3 = creat("5temp3.txt",0666);
	fd4 = creat("5temp4.txt",0666);
	fd5 = creat("5temp5.txt",0666);
	if((fd1 == -1) || (fd2 == -1) || (fd3 == -1) || (fd4 == -1) || (fd5 == -1))
	{
		perror("\ncreat");
		return 1;
	}
	
	while(1)
	{}

	return 0;
}
