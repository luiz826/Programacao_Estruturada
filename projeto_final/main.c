#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "matrix.h"


int main(void){

	struct matrix a;
	int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	a = create_matrix(array, 3, 3);

	printf("\n");
	printf("n_rows %d\n", a.n_rows);
	printf("n_cols %d\n", a.n_cols);
	printf("stride_rows %d\n", a.stride_rows);
	printf("stride_cols %d\n", a.stride_cols);
	printf("offset %d\n", a.offset);
	printf("\n");
	print_matrix(a);

	return 0;
}