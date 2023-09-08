#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	if(!fork())
	{
		//Child Process
		exit(0);
	}
	else
	{
		//Parent Process
		sleep(10);
	}
	return 0;
}
