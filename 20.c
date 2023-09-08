#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <string.h>
int main()
{
	int newp;
	printf("\nEnter New priority : ");
	scanf(" %d",&newp);
	
	int p = getpriority(PRIO_PROCESS , getpid());
	printf("\nCurrent priority is %d.\n",p);
	printf("\nAfter update : %d.\n",nice(newp));
	return 0;
}
