#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(){
	int pd;
	pd = open("foo", O_WRONLY | O_CREAT, 0644);
		if(pd < 0){
			printf("Error Number %d \n",errno);
			perror("foo");
			exit(1);
		}
	write(pd, "Hello World", 11);
	close(pd);
	return 0;
}
