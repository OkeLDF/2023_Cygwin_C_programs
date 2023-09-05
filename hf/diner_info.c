#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	printf("Diners: %s\n", argv[1]);
	printf("Juice: %s\n", getenv("JUICE"));
	return 0;
}
