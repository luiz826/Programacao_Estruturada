/* 
	Aluno: Caio Lucas da Silva Chacon	  | Matricula: 20200025
	Aluno: Luiz Fernando Costa dos Santos | Matricula: 20200025446
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "matrix.h"

int main(void){
	int data[] = {1, 2, 3, 4, 5, 6};
	struct matrix a_matrix = create_matrix(data, 3, 2);
	struct matrix zero = zeros_matrix(4, 4);
	struct matrix identity_matrix = i_matrix(4);
	struct matrix rand_matrix = random_matrix(3, 2, 0, 20);

	// Criação de matrizes
	print_matrix(a_matrix);
	printf("\n");
	print_matrix(rand_matrix);
	printf("\n");
	print_matrix(mul(a_matrix, a_matrix));
	printf("\n");
	print_matrix(division(rand_matrix, a_matrix));

	return 0;
}