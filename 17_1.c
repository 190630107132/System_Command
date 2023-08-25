#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/stat.h>

int main() {
    int fd;
    fd = open("temp17.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    fl.l_type = F_WRLCK;
    fl.l_pid = getpid();
    printf("Press enter to get lock");
    getchar();
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }
    int ticket;
    char buffer[20];
    printf("Enter the ticket number - ");
    scanf("%d", &ticket);
    snprintf(buffer, sizeof(buffer), "%d\n", ticket);
    ssize_t br;
    br = write(fd, buffer, strlen(buffer));
    if(br == -1){
        perror("Error in writing to the file");
        exit(1);
    }
    printf("Ticket reserved. Your ticket number is: %d\n", ticket);
    printf("Press enter to release lock");
    getchar();
    getchar();
    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }
    close(fd);
    return 0;
}
