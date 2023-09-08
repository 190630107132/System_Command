#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{	
	int temp1 = fork();
	if(temp1 == 0)
	{
		printf("\n Child process id is : %d\n",getpid());
		printf("\n My parent id is : %d\n",getppid());
	}	
	else
	{
		printf("\n Parent process id is : %d\n",getpid());
		printf("\n My child id is : %d\n",temp1);
	}
	return 0;
}
