#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#define BSIZE 16384

int main(){
    int pd_dst, pd_src;
    int n;
    char buf[BSIZE];
    pd_src = open("file.txt", O_RDONLY, 0644);
    if(pd_src < 0){
        printf("Failed to open the sorce file\n");
        perror("file.txt");
        exit(1);
    }
    pd_dst = open("foo", O_WRONLY | O_CREAT |O_TRUNC, 0644);
    if(pd_dst < 0 ){
        printf("Failed to open the destination file\n");
        perror("foo");
        exit(1);
    }
    while( (n = read(pd_src, buf, BSIZE)) > 0 ){
        if((write(pd_dst, buf, n)) != n){
            printf("Error while writng to the destination\n");
            exit(1);
        }
        
    }
    close(pd_src);
    close(pd_dst);
    printf("file successfully copied");
    return 0;

}