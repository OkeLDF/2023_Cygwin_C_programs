#include <stdio.h>
#include <unistd.h> // para usar: execle(), para executar um programa secundário
#include <errno.h> // para usar: errno, variável global para erros
#include <string.h> // para usar: strerror(), que transforma um número de erro numa mensagem

int main(){
	char *my_env[] = {"PATH=/cygwin64/usr/bin", "JUICE=apple", NULL};
	char prog[] = "/cygwin64/home/otavi/diner_info";
	
	if(execle(prog, prog, "4", NULL, my_env) == -1){
		puts(strerror(errno));
		return (1);
	}
	
	return 0;
}
