#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void error(const char* s){
	fprintf(stderr, "\nErro: %s.", s);
	exit(1);
}

int main(){
	FILE *fp;
	pid_t pid = fork();
	int status;
	
	if(pid == -1) error("falha ao bifurcar processo");
	
	if(pid != 0){
		if(waitpid(pid, &status, 0) == -1){
			char msg[100];
			sprintf(msg, "Process %d: Falha ao esperar processo filho (valor de retorno: %d)", pid, WEXITSTATUS(status));
			error(msg);
		}
		fp = fopen("C:\\cygwin64\\home\\otavi\\hf\\nota.txt", "w");
		if(!fp) error("falha ao abrir arquivo");
		
		// alguma especie de erro acontece: o printf antes de dup2() eh redirecionado tambem...
		
		printf("\n\nProcess %d: tudo sussa ;)\n", pid);
		dup2(fileno(fp), 1);
		printf("resultado:\nfuncoes exec(): 2\nfork() e pid: 2\nwaitpid() e WEXITSTATUS: 1\ndup2() e fileno(): 1\n\nTOTAL: 6/8");
		
		fclose(fp);
	}
	
	else{
		printf("\nProcess %d: yoyoyo\n", pid);
		
		char pathname[] = "C:\\cygwin64\\home\\otavi\\hf\\HelloWorld.exe";
		printf("\nExecuting process %d:\n", pid);
		if(execl(pathname, pathname, NULL) == -1){
			error(strerror(errno));
		}
	}
	
	return 0;
}
