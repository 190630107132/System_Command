#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
int main()
{
	// Get Scheduling Policy and modify the Scheduling Policy
	int policy = sched_getscheduler(getpid());
	switch(policy)
	{
		case SCHED_OTHER	:	printf("\n SCHED_OTHER..\n");
		break;
		case SCHED_RR		:	printf("\n SCHED_RR..\n");
		break;
		case SCHED_FIFO		:	printf("\n SCHED_FIFO..\n");
		break;
	}	
	// Changing the policy
	struct sched_param sp;
	sp.sched_priority = 10;
	int cs = sched_setscheduler(getpid(),SCHED_RR,&sp);
	policy = sched_getscheduler(getpid());
	printf("\n After changing the policy..\n");
        switch(policy)
        {
                case SCHED_OTHER        :       printf("\n SCHED_OTHER..\n");
                break;
                case SCHED_RR           :       printf("\n SCHED_RR..\n");
                break;
                case SCHED_FIFO         :       printf("\n SCHED_FIFO..\n");
                break;
        }  
	return 0;
}
