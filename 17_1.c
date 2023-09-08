#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
int main()
{
        int fd = open("data1.txt",O_RDWR);
        if(fd == -1)
        {
                perror("open");
                return 1;
        }
        printf("\nEnter number of tickets you want to book : ");
        int nt;
        scanf("%d",&nt);
        int data;
        char rd[5],wd[5];
        int r = read(fd,rd,5);
        if(r != 0)
        data = atoi(rd);
        else
                data = 0;
        data += nt;
        sprintf(wd,"%d",data);

        ftruncate(fd,5);
        lseek(fd,0,SEEK_SET);
        write(fd,wd,sizeof(wd));

        printf("\nData Updated!!\n");
        close(fd);
	return 0;
}
