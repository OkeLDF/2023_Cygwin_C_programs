/***************************************
 Warning: this code only runs in Cygwin!
 ***************************************/

#include <stdio.h>
#include <stdlib.h> // exit();
#include <unistd.h> // pid_t; fork();
#include <string.h> // strerror();
#include <errno.h> // errno;
#include <sys/wait.h> // waitpid();

int main(){
	pid_t pid = fork();
	int pid_status;
	
	if(pid == -1){
		fprintf(stderr, "%s\n", strerror(errno));
		return 1;
	}
	
	if(!pid){ // Processo filho
		printf("Processo filho [%d]: meu pai quer bolacha?\n", pid);
	}
	
	else{ // Processo pai
		if(waitpid(pid, &pid_status, 0) == -1){
			fprintf(stderr, "Falha ao esperar processo filho\n");
			fprintf(stderr, "exit status: %d\n", WEXITSTATUS(pid_status));
			exit(1);
		}
		
		printf("Processo pai [%d]: nao quero nao\n", pid);
	}
	
	return 0;
}
