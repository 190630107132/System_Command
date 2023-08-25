#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
    
int main(int argc, char *argv[])
{
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    int fd;
    fl.l_pid = getpid();
    if (argv[1][0] == 'r') 
    {
        fl.l_type = F_RDLCK;
    }
    else if (argv[1][0] == 'w') 
    {
        fl.l_type = F_WRLCK;
    }
    else
    {
	errExit("Error1");
    }
    if ((fd = open("example.txt", O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }
    printf("Press Enter to get lock: ");
    getchar();
    printf("Trying to get lock...");
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }
    printf("got lock\n");
    printf("Press Enter to release lock: ");
    getchar();
    fl.l_type = F_UNLCK;  /* set to unlock same region */
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }
    printf("Unlocked.\n");
    close(fd);
}
