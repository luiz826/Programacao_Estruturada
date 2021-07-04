/* 
	Aluno: Caio Lucas da Silva Chacon	  | Matricula: 20200025769
	Aluno: Luiz Fernando Costa dos Santos | Matricula: 20200025446
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "matrix.h"

int main(void){
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	struct matrix a_matrix = create_matrix(data, 3, 3);
	struct matrix an_i_matrix = i_matrix(3);


	print_matrix(an_i_matrix);
	printf("\n");
	print_matrix(a_matrix);
	printf("\n");
	matmul(an_i_matrix, a_matrix);
	printf("\n");

	return 0;
}