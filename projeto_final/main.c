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
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	struct matrix matrix_cm = create_matrix(data, 3, 3);
	struct matrix matrix_z = zeros_matrix(5, 4);
	struct matrix matrix_rand = random_matrix(4, 3, 1, 10);
	struct matrix matrix_i = i_matrix(3);
	
	printf("matrix cm: \n");
	print_matrix(matrix_cm);
	printf("zeros matrix: \n");
	print_matrix(matrix_z);
	printf("random matrix: \n");
	print_matrix(matrix_rand);
	printf("identity matrix: \n");
	print_matrix(matrix_i);
	
	printf("get element (0,1) of identity matrix: %d\n", get_element(matrix_i, 0, 1));
	printf("put element 9 in (0,1) in identity matrix: \n");
	put_element(matrix_i, 0, 1, 9);
	print_matrix(matrix_i);

	printf("transpose random matrix: \n");
	print_matrix(transpose(matrix_rand));
	printf("reshape zeros matrix: \n");
	print_matrix(reshape(matrix_z, 10, 2));
	printf("flatten identity matrix: \n");
	print_matrix(flatten(matrix_i));
	printf("slice matrix cm\n");
	print_matrix(slice(matrix_cm, 0, 1, 0, 3));
	
	printf("sum identity matrix: %d\n", sum(matrix_i));
	printf("mean matrix cm: %f\n", mean(matrix_cm));
	printf("min random matrix: %d\n", min(matrix_rand));
	printf("max random matrix: %d\n", max(matrix_rand));
	
	printf("add identity matrix and matrix cm: \n");
	print_matrix(add(matrix_i, matrix_cm));
	printf("sub identity matrix and matrix cm: \n");
	print_matrix(sub(matrix_cm, matrix_i));
	printf("division identity matrix and matrix cm: \n");
	print_matrix(division(matrix_i, matrix_cm));
	printf("mul identity matrix and matrix cm: \n");
	print_matrix(mul(matrix_i, matrix_cm));
	printf("matmul identity matrix and matrix cm: \n");
	print_matrix(matmul(matrix_i, matrix_cm));

	return 0;
}