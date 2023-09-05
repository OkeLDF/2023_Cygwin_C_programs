#include <stdio.h>

typedef enum{
	OP_ADD,
	OP_SUB,
	OP_MULT,
	OP_FDIV,
	OP_POW,
}type_e;

typedef struct{
	type_e type;
	int x_num;
	int y_num;
}op_t;

int power(int base, int pot){
	return (pot <= 0)? 1 : base * power(base, pot-1);
}

int calc(op_t *op){
	int result = 0;
	
	switch(op->type){
		case OP_ADD:
			result = op->x_num + op->y_num; break;
		
		case OP_SUB:
			result = op->x_num - op->y_num; break;

		case OP_MULT:
			result = op->x_num * op->y_num; break;

		case OP_FDIV:
			result = op->x_num / op->y_num; break;

		case OP_POW:
			result = power(op->x_num, op->y_num); break;
	}
	
	return result;
}

int main(){
	op_t op = {OP_ADD, 2, 3};
	printf("Resultado = %d", calc(&op));
	return 0;
}
