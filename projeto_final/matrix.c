#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "matrix.h"

/////////////////// Funções para criação de matrizes /////////////////

struct matrix create_matrix(int *data, int n_rows, int n_cols) {
	struct matrix self;

	self.data = &data[0];
	self.n_rows = n_rows;
	self.n_cols = n_cols;
	self.stride_rows = n_cols;
	self.stride_cols = 1;
	self.offset = 0;

	return self;
}


struct matrix zeros_matrix(int n_rows, int n_cols) {
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

	for (int i=a_matrix.offset; i<a_matrix.n_rows; i++){
		for (int j=a_matrix.offset; j<a_matrix.n_cols; j++){
			
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

	for (int i = a_matrix.offset; i<(a_matrix.n_rows*a_matrix.n_cols); i++){
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
	for (int i=a_matrix.offset; i<dim; i++){
		s += a_matrix.data[i];
	}

	return s;
}

int mean(struct matrix a_matrix) {
	int s, dim, i;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	s = 0;
	for (i=a_matrix.offset; i<dim; i++){
		s += a_matrix.data[i];
	}

	return s/i;
}

int min(struct matrix a_matrix){
	int dim;
	int mini;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	mini = INT_MAX; 
	for (int i=a_matrix.offset; i<dim; i++){
		if (mini > a_matrix.data[i]){
			mini = a_matrix.data[i];
		}
	}

	return mini;
}

int max(struct matrix a_matrix){
	int dim;
	int maxi;

	dim = (a_matrix.n_cols*a_matrix.n_rows);

	maxi = 0;
	for (int i=a_matrix.offset; i<dim; i++){
		if (maxi < a_matrix.data[i]){
			maxi = a_matrix.data[i];
		}
	}

	return maxi;
}

////////////////////Funções de operações aritméticas//////////////////