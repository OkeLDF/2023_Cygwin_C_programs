#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	FILE *fp;
	pid_t pid = fork();
	
	if(pid == -1) exit(1);
	
	if(pid != 0){
		int status;
		if(waitpid(pid, &status, 0)==-1) exit(2);
		fopen("C:\\cygwin64\\home\\otavi\\hf\\teste.txt", "w");
		if(!fp) exit(3);
		printf("oi\n");
		dup2(fileno(fp), 1);
		printf("tchau\n");
		fclose(fp);
	}
	else{
		printf("saci");
	}
	
	return 0;
}

