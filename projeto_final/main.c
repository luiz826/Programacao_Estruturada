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
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	struct matrix a_matrix = create_matrix(data, 2, 5);

	int data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	struct matrix b_matrix = create_matrix(data1, 5, 4);
	//struct matrix an_i_matrix = i_matrix(3);


	//print_matrix(an_i_matrix);
	//printf("\n");
	//print_matrix(a_matrix);
	//printf("\n");
	struct matrix c_matrix = matmul(a_matrix, b_matrix);
	print_matrix(c_matrix);
	//for (int i =0; i<9; i++){
	//	printf("%d ", c_matrix.data[i]);
	//}
	//printf("\n");

	return 0;
}