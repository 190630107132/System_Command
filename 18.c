#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct items{
  int item_id;
  char item_name[20];
  int item_price;
};

void main() {
  struct flock lock;
  int fd=open("records.txt", O_CREAT | O_RDWR, 0777);
  struct items i1, i2, i3;
  i1.item_id=1;
  i2.item_id=2;
  i3.item_id=3;
  strcpy(i1.item_name, "ab");
  strcpy(i2.item_name, "cd");
  strcpy(i3.item_name, "ef");
  i1.item_price=199;
  i2.item_price=500;
  i3.item_price=1999;
  write(fd, &i1, sizeof(struct items));
  lock.l_type=F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 8;
  lock.l_len = 8;
  lock.l_pid = getpid();
  fcntl(fd,F_SETLKW , &lock);
  printf("Entered critical section...\n");
  printf("Press enter to unlock...\n");
  getchar();
  printf("Write lock unset...\n");
  lock.l_type=F_RDLCK;
  lock.l_start=0;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Read lock set...\n");
  lock.l_type=F_UNLCK;
  lock.l_start=8;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Press enter to exit...\n");
  getchar();
  printf("Read lock unset...\n");
  close(fd);
}
