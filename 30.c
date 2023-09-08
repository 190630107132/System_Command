#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{

    time_t c, d;
    struct tm *deadline;

    pid_t child;

    if (argc < 2)
    {
    	perror("\nEnter atleast 1 argument\n");
    	return 1;
    }
    else
    {
        time(&c);
        deadline = localtime(&c);

        deadline->tm_hour = atoi(argv[1]);
        deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
        deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

        d = mktime(deadline);

        if ((child = fork()) == 0)
        {
            setsid();
            chdir("/");
            umask(0);
            do
            {
                time(&c);
            } while (difftime(d, c) > 0);
            printf("I am HERE ;)\n");
        }
        return 0;
    }
}
