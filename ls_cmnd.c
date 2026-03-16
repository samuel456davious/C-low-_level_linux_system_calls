#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(){
	int pd;
	pd = open("dir_ls", O_WRONLY | O_CREAT, 0644);
	DIR *directory;
	struct dirent *entry;
	directory = opendir(".");
	if(directory == NULL){
		printf("Failed to open dir\n");
		perror("directory");
		return 1;

	}

	while((entry = readdir(directory)) != NULL){
		printf("%s\n", entry->d_name);
		write(pd, entry->d_name, strlen(entry->d_name) );

		write(pd, "\n", 1);
		
	}
	if((closedir(directory)) == -1){
			printf("Error occured while closing the dir");
			perror("directory");
			return 1;


		}
	return 0;
	}

	


