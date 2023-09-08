#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int p = fork();
	if(p != 0)
	{
		printf("\nIn parent process\n");
		exit(0);
	}
	else if(p == 0)
	{
		sleep(10);
		printf("\nIn child process\n");
	}
	return 0;
}
