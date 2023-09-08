#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid1 = fork();
	if(pid1 == -1)
	{
		printf("\n Erron in frok 1\n");
		return 1;
	}
	else if(pid1==0)
	{
		sleep(15);
		printf("\n Completed with process 1: %d\n",getpid());
	}
	else if(pid1 > 0)
	{
		int pid2 = fork();
		if(pid2 == -1)
		{
                	printf("\n Erron in frok 2\n");
                	return 1;
        	}
        	else if(pid2==0)
        	{
                	sleep(10);
                	printf("\n Completed with process 2: %d\n",getpid());
        	}
		else if(pid2 > 0)
		{
			int pid3 = fork();
			if(pid3 == -1)
                	{
                        	printf("\n Erron in frok 3\n");
                        	return 1;
                	}
                	else if(pid3==0)
                	{
                        	sleep(5);
				printf("\n Completed with process 3: %d\n",getpid());
                	}
			else if(pid3 > 0)
			{
				// Main Parent
				int pid_res = waitpid(pid1,NULL,0);
				printf("\nWaited for %d\n",pid_res);

			}
		}
		
		
	}
	return 0;
}
