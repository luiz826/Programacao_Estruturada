#include <stdio.h>
#include <stdlib.h>
//#include "matrix.h"

struct matrix {
int *data;
int n_rows;
int n_cols;
int stride_rows;
int stride_cols;
int offset;
};

// EM TEORIA ISSO TA CERTO
struct matrix create_matrix(int *data, int n_rows, int n_cols) {
	struct matrix b;
	b.data = data;
	b.n_rows = n_rows;
	b.n_cols = n_cols;
	b.stride_rows = n_rows;
	b.stride_cols = 1;
	b.offset = 0;

	return b;
}

// ERRADO. PQ TA ERRADO?????
struct matrix zero_matrix(int n_rows, int n_cols){
	int dim;
	struct matrix c;

	dim = n_rows * n_cols;

	int array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for (int i=0; i<9; i++){
		printf("%d, ", array[i]);
	}
	c = create_matrix(array, n_rows, n_cols);

	return c;
}

// FUNÇÃO MAIN PARA TESTAR O QUE TA DANDO ERRADO
int main(void){
	struct matrix a;
	//int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	a = zero_matrix(3, 3);

	for (int i=0; i<9; i++){
		printf("%d, ", a.data[i]);
	}

	printf("\n");
	printf("%d\n", a.n_rows);
	printf("%d\n", a.n_cols);
	printf("%d\n", a.stride_rows);
	printf("%d\n", a.stride_cols);
	printf("%d\n", a.offset);


	return 0;
}
