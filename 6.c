#include<stdio.h>
#include<unistd.h>

int main()
{
	char buff[1024];
	read(0,&buff,sizeof(buff));
	write(1,&buff,sizeof(buff));
	return 0;
}
