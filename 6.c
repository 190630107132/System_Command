#include<stdio.h>
#include<unistd.h>

int main()
{
	char buff[1024];
	
	int byte_read = read(0,&buff,sizeof(buff));
	printf("\n%d bytes read from user.\n",byte_read);
	printf("\n");
	int byte_write = write(1,&buff,byte_read);
	printf("\n%d bytes write to the terminal.\n",byte_write);
	
	return 0;
}
