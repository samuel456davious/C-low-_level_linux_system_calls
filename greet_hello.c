#include <fcntl.h>
#include <unistd.h>
int main(){
	int fd;
	fd = open("foo", O_WRONLY | O_CREAT, 0644);
	write(fd, "Hello World", 11);
	close(fd);
}
