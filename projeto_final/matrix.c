#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


// ERRADO. PQ TA ERRADO????? - Deu certo assim
struct matrix zero_matrix(int n_rows, int n_cols) {
	int dim = (n_rows*n_cols);
	int ar[dim];

	memset(ar, 0, dim*sizeof(ar[0]));

	return create_matrix(ar, n_rows, n_cols);
}


// Deu certo tbm (primeiro eu fiz a matriz de zeros[não usei o 
// zero_matrix pq deu merda] e depois coloquei 1 na diagonal principal)
struct matrix i_matrix(int n) {
	int dim = n*n;
	int ar[dim];

	memset(ar, 0, dim*sizeof(ar[0]));

	for (int i=0; i<dim; i = i+(n+1)){
		ar[i] = 1;
	}

	return create_matrix(ar, n, n);
}



/////////////////////////////////////////////////////////////////////
////////////////////////////////MAIN/////////////////////////////////
/////////////////////////////////////////////////////////////////////

// FUNÇÃO MAIN PARA TESTAR O QUE TA DANDO ERRADO
int main(void){
///////////////////////////TESTE1////////////////////////////////////

	struct matrix a;
	int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	a = create_matrix(array, 3, 3);

	for (int i=0; i<(a.n_rows*a.n_cols); i++){
	  	printf("%d, ", a.data[i]);
	}

	printf("\n");
	printf("%d\n", a.n_rows);
	printf("%d\n", a.n_cols);
	printf("%d\n", a.stride_rows);
	printf("%d\n", a.stride_cols);
	printf("%d\n", a.offset);
	printf("\n");
//////////////////////////TESTE2////////////////////////////////////

	struct matrix b;	

	b = zero_matrix(3, 3);

	for (int i=0; i<(b.n_rows*b.n_cols); i++){
	  	printf("%d, ", b.data[i]);
	}

	printf("\n");
	printf("%d\n", b.n_rows);
	printf("%d\n", b.n_cols);
	printf("%d\n", b.stride_rows);
	printf("%d\n", b.stride_cols);
	printf("%d\n", b.offset);
	printf("\n");
//////////////////////////TESTE3////////////////////////////////////

	struct matrix c;	

	c = i_matrix(3);

	for (int i=0; i<(c.n_rows*c.n_cols); i++){
	  	printf("%d, ", c.data[i]);
	}

	printf("\n");
	printf("%d\n", c.n_rows);
	printf("%d\n", c.n_cols);
	printf("%d\n", c.stride_rows);
	printf("%d\n", c.stride_cols);
	printf("%d\n", c.offset);
	printf("\n");

	return 0;
}
