#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
void find_sl(int fd, struct flock *fl,int *rd)
{

	int cc = 2;    
        char ch;
	char r[10];
        int temp=0;
        while(cc > 0)
        {
                temp++;
                read(fd,&ch,1);
                if(ch == ',')
        	cc--;
        }
	
        int i=0;
        fl->l_start = temp+1;
	while(ch != '\\')
	{
		read(fd,&ch,1);
		if(ch != '\\')
		r[i++] = ch;
	}
        
	fl->l_len = i;
	*rd = atoi(r);
}
int main()
{
	int fd = open("18.txt",O_RDWR);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}

	struct flock fl;
	fl.l_whence = SEEK_SET;
        fl.l_pid = getpid();

	int rd;
	int choice;
	int line;
	printf("\nRecord Number (1-3) : ");
	scanf(" %d",&choice);
	char ch;
	char wd[5];
	int read_c=0;
	switch(choice)
	{
		case	1	:	find_sl(fd,&fl,&rd);
					//printf("\nStart: %ld	Len: %ld.\n",fl.l_start,fl.l_len);
					//printf("\nNumber is %d. \n",rd);
		break;
		case	2	:	line = 1;
					while(line)
					{
						read(fd,&ch,1);
						if(ch == '\\')
						{
							line--;
						}else
							read_c++;
					}
					find_sl(fd,&fl,&rd);
					fl.l_start = fl.l_start + read_c;
		break;
		case	3	:	line = 2;
                                        while(line)
                                        {
                                                read(fd,&ch,1);
                                                if(ch == '\\')
                                                {
                                                        line--;
                                                }else
                                                        read_c++;

                                        }
                                        find_sl(fd,&fl,&rd);
                                        fl.l_start = fl.l_start + read_c;
		break;
	}
	printf("\nEnter your choice:\n1.Read\n2.Write\n---> ");
	scanf(" %d",&choice);
	
	switch(choice)
	{
		case	1	:	printf("\nTrying to get lock.\n");
					fl.l_type = F_RDLCK;
					if(fcntl(fd,F_SETLK,&fl) == -1)
					{
						perror("fcntl");
						return 1;
					}
					printf("\nLock set!!\n");
					printf("\nThe data is %d.\n",rd);
					
					printf("\nPlease enter to release lock.\n");
					getchar();
					getchar();
					
					fl.l_type = F_UNLCK;
	
					if(fcntl(fd,F_SETLKW,&fl) == -1)
					{
						perror("fcntl");
						return 1;
					}
					printf("\nLock Unset!!\n");
		break;
		case	2	:	fl.l_type = F_WRLCK;
					printf("\nTrying to get lock.\n");
					if(fcntl(fd,F_SETLKW,&fl) == -1)
					{
						perror("fcntl");
						return 1;
					}
					printf("\nLock set!!\n");
					printf("\nData before update is %d.\n",rd);
					printf("\nEnter new data (len should be less than 5) : ");
					int mkp;
					scanf(" %d",&mkp);
					sprintf(wd,"%d",mkp);
					
					if(strlen(wd) > 6)
					{
						perror("Lenght");
						return 1;
					}
					long int str_len = strlen(wd);
					printf("\nString length is %ld.\n",str_len);
					long int x=str_len;
					while(x<5)
					{
						if(x == 4)
						{
							wd[x] = '\\';
						}
						else
						wd[x] = ' ';
						x++;
						
					}
					
					printf("\nNumber in string is %s.\n",wd);
					lseek(fd,-5,SEEK_CUR);
					write(fd,wd,sizeof(wd));
					
					printf("\nPlease enter to release lock.\n");
					getchar();
					getchar();
					fl.l_type = F_UNLCK;
	
					if(fcntl(fd,F_SETLKW,&fl) == -1)
					{
						perror("fcntl");
						return 1;
					}
					printf("\nLock Unset!!\n");
		break;
	}
	close(fd);	
	return 0;
}
