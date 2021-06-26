#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
//#include "matrix.h"



struct matrix {
	int *data;
	int n_rows;
	int n_cols;
	int stride_rows;
	int stride_cols;
	int offset;
};


/////////////////// Funções para criação de matrizes /////////////////

struct matrix create_matrix(int *data, int n_rows, int n_cols) {
	struct matrix self;

	self.data = data;
	self.n_rows = n_rows;
	self.n_cols = n_cols;
	self.stride_rows = n_rows;
	self.stride_cols = 1;
	self.offset = 0;

	// CAIO CHECANDO
	//for (int i=0; i<(n_rows*n_cols); i++){
	//	printf("%d ", data[i]);
	//}
	return self;
}


struct matrix zero_matrix(int n_rows, int n_cols) {
	int dim;
	dim = (n_rows*n_cols);
	int ar[dim];

	memset(ar, 0, dim*sizeof(ar[0]));

	
	return create_matrix(ar, n_rows, n_cols);
}


struct matrix random_matrix(int n_rows, int n_cols, int b, int e){
	int dim, quantidade = 0;
	dim = (n_rows*n_cols);
	int ram[dim];

	srand(time(NULL));


	quantidade = e - b + 1;

	for (int i = 0; i<dim; i++){
		ram[i] = (rand() % quantidade) + b;
	}

	return create_matrix(ram, n_rows, n_cols);
}


struct matrix i_matrix(int n) {
	int dim;
	dim = n*n;
	int ar[dim];

	memset(ar, 0, dim*sizeof(ar[0]));

	for (int i=0; i<dim; i = i+(n+1)){
		ar[i] = 1;
	}

	return create_matrix(ar, n, n);
}

////////// Funções para acessar elementos ///////////////////////////

int get_element(struct matrix a_matrix, int ri, int ci){
	int index;

	index = (ri*a_matrix.stride_rows) + (ci*a_matrix.stride_cols);

	return a_matrix.data[index];
}


void put_element(struct matrix a_matrix, int ri, int ci, int elem){
	int index;

	index = (ri*a_matrix.stride_rows) + (ci*a_matrix.stride_cols);

	a_matrix.data[index] = elem;
}

// O print_matrix ta errado ou é o zero_matrix, i_matrix e random matrix?
void print_matrix(struct matrix a_matrix){
	int cont;

	cont = 0;

	for (int i=0; i<a_matrix.n_rows; i++){
		for (int j=0; j<a_matrix.n_cols; j++){
			
			if (j == 0) {
				printf("|");
			}
			
			printf("%2.d ", a_matrix.data[cont]);
			cont++;

			if (j == a_matrix.n_cols-1){
				printf("|");	
			}
		}
		printf("\n");
	}

}
/////////// Funções para manipulação de dimensões ///////////////////////////

struct matrix transpose(struct matrix a_matrix){
	int temp_n_cols, temp_n_rows, temp_stride_rows;

	temp_n_cols = a_matrix.n_cols;
	temp_n_rows = a_matrix.n_rows;
	temp_stride_rows = a_matrix.stride_rows;

	a_matrix.n_cols = temp_n_rows;
	a_matrix.n_rows = temp_n_cols;
	a_matrix.stride_rows = temp_n_cols;

	// retorno a_matrix ou outro create_matrix?
	return a_matrix;
}

struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){
	int quantidade_de_elementos = 0; 

	for (int i = 0; i<(a_matrix.n_rows*a_matrix.n_cols); i++){
		quantidade_de_elementos++;
	}

	if (quantidade_de_elementos == new_n_rows * new_n_cols){
		a_matrix.n_rows = new_n_rows;
		a_matrix.n_cols = new_n_cols;
		a_matrix.stride_rows = new_n_rows;

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
//////////////////// Funções de agregação ///////////////////////////


int sum(struct matrix a_matrix) {
	int s, dim;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	s = 0;
	for (int i=0; i<dim; i++){
		s += a_matrix.data[i];
	}

	return s;
}

int mean(struct matrix a_matrix) {
	int s, dim, i;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	s = 0;
	for (i=0; i<dim; i++){
		s += a_matrix.data[i];
	}

	return s/i;
}

int min(struct matrix a_matrix){
	int dim;
	int min;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	min = INT_MAX; 
	for (int i=0; i<dim; i++){
		if (min > a_matrix.data[i]){
			min = a_matrix.data[i];
		}
	}

	return min;
}

int max(struct matrix a_matrix){
	int dim;
	int max;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	max = 0;
	for (int i=0; i<dim; i++){
		if (max < a_matrix.data[i]){
			max = a_matrix.data[i];
		}
	}

	return max;
}



/////////////////////////////////////////////////////////////////////
////////////////////////////////MAIN/////////////////////////////////
/////////////////////////////////////////////////////////////////////

// FUNÇÃO MAIN PARA TESTAR O QUE TA DANDO ERRADO
/*
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

//////////////////////////TESTE4////////////////////////////////////

	printf("\n");
	printf("%d\n",  get_element(a, 1, 0));
	printf("\n");
	print_matrix(a);
	printf("\n");
	put_element(a, 1, 0, 99);
	print_matrix(a);
	printf("\n");
//////////////////////////TESTE5////////////////////////////////////

	printf("\n");
	printf("%d\n",  sum(a));
	printf("%d\n", mean(a));
	printf("%d\n",  min(a));
	printf("%d\n",  max(a));
	printf("\n");


	// se passar b no lugar de i_matrix, da errado
	printf("\n");
	printf("%d\n",  sum(zero_matrix(3,2)));
	printf("%d\n", mean(zero_matrix(3,2)));
	printf("%d\n",  min(zero_matrix(3,2)));
	printf("%d\n",  max(zero_matrix(3,2)));
	printf("\n");


	// se passar c no lugar de i_matrix, da errado
	printf("\n");
	printf("%d\n",  sum(i_matrix(5))); 
	printf("%d\n", mean(i_matrix(5)));
	printf("%d\n",  min(i_matrix(5)));
	printf("%d\n",  max(i_matrix(5)));
	printf("\n");


	return 0;
}
*/
int main(void){
	int array[6] = {1, 2, 3, 4, 5, 6};

	//print_matrix((2, 3, 0, 3));
	print_matrix(flatten(create_matrix(array, 2, 3)));

	
	return 0;
}