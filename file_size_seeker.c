#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
 int main (){
    int fd, file_size;
    // opnening the file
    fd = open("/sys/class/net/wlan0/address", O_RDONLY, 0644);
    // checking if the opening operation was successfully
    if(fd < 0){
        perror("/sys/class/net/wlan0/address");
        exit(1);
    }
    // using lseek to get the number of bytes
    file_size = lseek(fd, 0, SEEK_END);
    printf("Then number of bytes in this file is :%d", file_size);
    return 0;

 }