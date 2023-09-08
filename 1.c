#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
        int v = symlink("temp1.txt","destSL");
        
        if(v == -1)
        {
        	perror("symlink");
        	return 1;
        }
        else
        {
        	printf("\nSofytlink created..\n");
        }
        
        int f = link("temp1.txt","destHL");
        
        if(f == -1)
        {
        	perror("link"); 
        	return 1;
        }
        else
        {
        	printf("\nHardlink created..\n");
        }
        
        int e = mknod("destFIFO",S_IFIFO,0);
        if(e == -1)
	{
		perror("mknod");
		return 1;
	}
	else
	{
		printf("\nFIFO created..\n");
	}
        
        return 0;
}

