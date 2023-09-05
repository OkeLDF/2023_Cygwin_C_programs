#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error(const char *msg){
	printf("error: %s.", msg);
	exit(1);
}

int main(){
	pid_t pid;
	int fd[2];
	
	if(pipe(fd) == -1) error("can't create the pipe");
	
	if((pid=fork()) == -1) error("can't fork");
	
	if(pid){
		close(fd[1]);
		dup2(fd[0], 0);
		
		char str[17];
		fgets(str, sizeof(str), stdin);
		printf("%s", str);
	}
	
	else{
		close(fd[0]);
		dup2(fd[1], 1);
		
		printf("Hello World");
	}
}
