/* 
	Aluno: Caio Lucas da Silva Chacon	  | Matricula: 20200025769
	Aluno: Luiz Fernando Costa dos Santos | Matricula: 20200025446
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "matrix.h"


/* 
	array

*/

/////////////////// Funções para criação de matrizes /////////////////

struct matrix create_matrix(int *data, int n_rows, int n_cols) {
	struct matrix self;

	self.data = data;
	self.n_rows = n_rows;
	self.n_cols = n_cols;
	self.stride_rows = n_cols;
	self.stride_cols = 1;
	self.offset = 0;

	return self;
}


struct matrix zeros_matrix(int n_rows, int n_cols) {
	int dim = (n_rows*n_cols);
	int *zeros = malloc(dim * sizeof(int));

	for (int i=0; i<dim; i++){
		zeros[i]= 0;
	}

	struct matrix a_matrix = create_matrix(zeros, n_rows, n_cols);
	return a_matrix;
}	


struct matrix random_matrix(int n_rows, int n_cols, int b, int e){
	int dim =(n_rows*n_cols), quantidade = 0;
	int *random = malloc(dim * sizeof(int));

	srand(time(NULL));
	quantidade = e - b + 1;

	for (int i = 0; i<dim; i++){
		random[i] = (rand() % quantidade) + b;
	}

	struct matrix a_matrix = create_matrix(random, n_rows, n_cols);
	return a_matrix;
}


struct matrix i_matrix(int n) {
	int dim = n*n;
	struct matrix a_matrix = zeros_matrix(n, n);

	for (int i=a_matrix.offset; i<dim; i = i+(n+1)){
		a_matrix.data[i] = 1;
	}

	return a_matrix;
}

////////// Funções para acessar elementos ///////////////////////////

int get_element(struct matrix a_matrix, int ri, int ci){
	int index = (ri*a_matrix.stride_rows) + (ci*a_matrix.stride_cols);

	return a_matrix.data[index];
}


void put_element(struct matrix a_matrix, int ri, int ci, int elem){
	int index = (ri*a_matrix.stride_rows) + (ci*a_matrix.stride_cols);

	a_matrix.data[index] = elem;
}


void print_matrix(struct matrix a_matrix){
	// to debug
	printf("nrows: %d\nncols: %d\nstrows: %d\nstcols: %d\noffset: %d\n", a_matrix.n_rows, a_matrix.n_cols, a_matrix.stride_rows, a_matrix.stride_cols, a_matrix.offset);


	for (int i=0; i<a_matrix.n_rows; i++){
		for (int j=0; j<a_matrix.n_cols; j++){
			
			if (j == 0) {
				printf("|");
			}
			
			printf(" %d ", a_matrix.data[( (i*a_matrix.stride_rows) + (j*a_matrix.stride_cols) ) + a_matrix.offset]);

			if (j == a_matrix.n_cols-1){
				printf("|");	
			}
		}
		printf("\n");
	}

}
/////////// Funções para manipulação de dimensões ///////////////////////////

struct matrix transpose(struct matrix a_matrix){
	int temp_n_cols, temp_n_rows, temp_stride_rows, temp_stride_cols;

	temp_n_cols = a_matrix.n_cols;
	temp_n_rows = a_matrix.n_rows;
	temp_stride_rows = a_matrix.stride_rows;
	temp_stride_cols = a_matrix.stride_cols;

	a_matrix.n_cols = temp_n_rows;
	a_matrix.n_rows = temp_n_cols;
	a_matrix.stride_rows = temp_stride_cols;
	a_matrix.stride_cols = temp_stride_rows;

	return a_matrix;
}

struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){
	int quantidade_de_elementos = 0; 

	for (int i = a_matrix.offset; i<(a_matrix.n_rows*a_matrix.n_cols); i++){
		quantidade_de_elementos++;
	}

	if (quantidade_de_elementos == new_n_rows * new_n_cols){
		a_matrix.n_rows = new_n_rows;
		a_matrix.n_cols = new_n_cols;
		a_matrix.stride_rows = new_n_cols;
	} else{
		printf("Impossível realizar o reshape. Insira uma quantidade de elementos válida.\n");
		exit(1);
	}

	return a_matrix;
}	

struct matrix flatten(struct matrix a_matrix){
	a_matrix.n_cols = a_matrix.n_cols * a_matrix.n_rows;
	a_matrix.stride_rows = a_matrix.n_cols;  
	a_matrix.n_rows = 1;

	return a_matrix;
}

struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce) {
	a_matrix.n_rows = re-rs;  
	a_matrix.n_cols = ce-cs;
	a_matrix.offset = rs*a_matrix.stride_rows+cs*a_matrix.stride_cols;

	return a_matrix;
}

//////////////////// Funções de agregação ///////////////////////////


int sum(struct matrix a_matrix) {
	int summ = 0, dim = (a_matrix.n_cols*a_matrix.n_rows);;

	for (int i=a_matrix.offset; i<dim; i++){
		summ += a_matrix.data[i];
	}

	return summ;
}

float mean(struct matrix a_matrix) {
	float summ = 0, dim = (a_matrix.n_cols*a_matrix.n_rows);
	int i;

	for (i=a_matrix.offset; i<dim; i++){
		summ += a_matrix.data[i];
	}

	return summ/i;
}

int min(struct matrix a_matrix){
	int dim = (a_matrix.n_cols*a_matrix.n_rows), mini = INT_MAX;

	for (int i=a_matrix.offset; i<dim; i++){
		if (mini > a_matrix.data[i]){
			mini = a_matrix.data[i];
		}
	}

	return mini;
}

int max(struct matrix a_matrix){
	int dim = (a_matrix.n_cols*a_matrix.n_rows), maxi = 0;

	for (int i=a_matrix.offset; i<dim; i++){
		if (maxi < a_matrix.data[i]){
			maxi = a_matrix.data[i];
		}
	}

	return maxi;
}

////////////////////Funções de operações aritméticas//////////////////

struct matrix add(struct matrix a_matrix, struct matrix b_matrix) {
	int dim_a = (a_matrix.n_cols*a_matrix.n_rows);
	int dim_b = (b_matrix.n_cols*b_matrix.n_rows);

	if (dim_a != dim_b){
		printf("Impossível realizar a soma. Insira uma quantidade de elementos válida.\n");
		exit(1);
	}

	int *soma = malloc(dim_a * sizeof(int));

	for (int i=0; i<dim_a; i++) {
		soma[i] = a_matrix.data[i]+b_matrix.data[i];
	}

	struct matrix soma_matrix = create_matrix(soma, a_matrix.n_rows, a_matrix.n_cols);
	return soma_matrix;
}

struct matrix sub(struct matrix a_matrix, struct matrix b_matrix){
	int dim_a = (a_matrix.n_cols*a_matrix.n_rows);
	int dim_b = (b_matrix.n_cols*b_matrix.n_rows);

	if (dim_a != dim_b){
		printf("Impossível realizar a subtração. Insira uma quantidade de elementos válida.\n");
		exit(1);
	}

	int *subs = malloc(dim_a * sizeof(int));

	for (int i=0; i<dim_a; i++) {
		subs[i] = a_matrix.data[i]-b_matrix.data[i];
	}

	struct matrix subs_matrix = create_matrix(subs, a_matrix.n_rows, a_matrix.n_cols);
	return subs_matrix;
}

struct matrix division(struct matrix a_matrix, struct matrix b_matrix) {
	int dim_a = (a_matrix.n_cols*a_matrix.n_rows);
	int dim_b = (b_matrix.n_cols*b_matrix.n_rows);

	if (dim_a != dim_b){
		printf("Impossível realizar a divisão. Insira uma quantidade de elementos válida.\n");
		exit(1);
	}

	int *divi = malloc(dim_a * sizeof(int));

	for (int i=0; i<dim_a; i++) {
		if (b_matrix.data[i] == 0){
			printf("Impossível realizar a divisão por 0. Insira uma quantidade de elementos válida.\n");
			exit(1);
		}

		divi[i] = a_matrix.data[i]/b_matrix.data[i];
	}

	struct matrix divi_matrix = create_matrix(divi, a_matrix.n_rows, a_matrix.n_cols);
	return divi_matrix;
}

struct matrix mul(struct matrix a_matrix, struct matrix b_matrix) {
	int dim_a = (a_matrix.n_cols*a_matrix.n_rows);
	int dim_b = (b_matrix.n_cols*b_matrix.n_rows);

	if (dim_a != dim_b){
		printf("Impossível realizar a multiplicação. Insira uma quantidade de elementos válida.\n");
		exit(1);
	}

	int *mult = malloc(dim_a * sizeof(int));

	for (int i=0; i<dim_a; i++) {
		mult[i] = a_matrix.data[i]*b_matrix.data[i];

	}

	struct matrix mult_matrix = create_matrix(mult, a_matrix.n_rows, a_matrix.n_cols);
	return mult_matrix;
}


struct matrix matmul(struct matrix a_matrix, struct matrix b_matrix){
	if (a_matrix.n_cols != b_matrix.n_rows) {
		printf("Impossível realizar a multiplicação. Insira uma quantidade de elementos válida.\n");
		exit(1);
	}

	int dim = a_matrix.n_rows*b_matrix.n_cols;
	int *matmult = malloc(dim * sizeof(int));

	// Transformo matmult num array de zeros para poder fazer operações sobre eles
	for (int i=0; i<dim; i++){
		matmult[i]= 0;
	}

	int p = 0;
	int m = 0;

	//printf("a_stride_rows: %d\n", a_matrix.stride_rows);
	//printf("b_stride_rows: %d\n", b_matrix.stride_rows);

	for (int i=0; i<dim; i++){
		//for (int k=0; k<b_matrix.stride_rows*b_matrix.n_cols; k+=b_matrix.stride_rows){
			int k = 0;

			for (int j=0; j<a_matrix.n_cols; j++){
				m = j;
				m += a_matrix.stride_rows * (i / b_matrix.stride_rows);

				if (i % b_matrix.stride_rows == 0){
					p = 0;
				}
				// (0, 1, 2) * (0 ,1, 2)
				// (3, 4, 5)   (3, 4, 5)
				// (6, 7, 8)   (6, 7, 8)

				// (0*0 + 1*3 + 2*6 , 0*1 + 1*4 + 2*7, 0*2 + 1*5, 2*8)
				// (3*0 + 4*3 + 5*6 , 3*1 + 4*4 + 5*7, 3*2 + 4*5, 5*8)
				// (6*0 + 7*3 + 8*6 , 6*1 + 7*4 + 8*7, 6*2 + 7*5, 8*8)

				// (0, 1) * (0. 1)
				// (2, 3)	(2, 3)

				// (0*0 + 1*2, 0*1 + 1*3)
				// (2*0 + 3*2, 2*1 + 3*3)

				// (0, 1, 2) * (0, 1)
				// (3, 4, 5)   (2, 3)
				//			   (4, 5)

				// (0*0 + 1*2 + 2*4, 0*1 + 1*3 + 2*5)
				// (3*0 + 4*2 + 5*4, 3*1 + 4*3 + 5*5)

				matmult[i] += a_matrix.data[m] * b_matrix.data[k+p];
				
				printf("%d * %d\n", a_matrix.data[m], b_matrix.data[k+p]);

				k += b_matrix.stride_rows;
			}
			//printf("\n");
			//printf("elemento: %d", matmult[i]); 
			p++;
			printf("\n");

	}

	struct matrix matmult_matrix = create_matrix(matmult, a_matrix.n_rows, b_matrix.n_cols);
	return matmult_matrix;

}
