#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char *my_env[] = {"PATH=/cygwin64/usr/bin", "JUICE=apple", NULL};
	char prog[] = "/cygwin64/home/otavi/hf/diner_info";
	
	execle(prog, prog, "4", NULL, my_env);
	
	printf("KOKOKOKOKO");
	
	return 0;
}
