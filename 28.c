#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	// Changing the priority value
	struct sched_param sp;
	sp.sched_priority = 1;
	// Maximum and minimum priority of the scheduling policy
	int pid = getpid();	
	int policy = -1;
        policy = sched_getscheduler(pid);
	int change_scheduler = sched_setscheduler(pid,SCHED_FIFO,&sp);
	if(change_scheduler == -1)
	{
		perror("Sched_setscheduler");
		return 1;
	}
	policy = sched_getscheduler(pid);
	switch(policy)
	{
		case SCHED_OTHER : printf("\nSCHED_OTHER..\n");
		break;
		case SCHED_RR : printf("\nSCHED_RR..\n");
		break;
		case SCHED_FIFO : printf("\nSCHED_FIFO..\n");
		break;
	}
	printf("\n Process ID : %d \t Policy : %d\n",pid,policy);
	int max = sched_get_priority_max(policy);
	int min = sched_get_priority_min(policy);

	printf("\n Maximum scheduling priority is %d.\n Minimum scheduling priority is %d.\n",max,min);
	return 0;
}
