#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
	unsigned long long dst;
	__asm__ __volatile__("rdtsc": "=A"(dst));
	return dst;
}

int main()
{
	long long int start,end;
	start = rdtsc();
	getpid();
	end = rdtsc();
	printf("\nTime taken by CPU to execute getpid() : %llu\n",end-start);
	return 0;
}
