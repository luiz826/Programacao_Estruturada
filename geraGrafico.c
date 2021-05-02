// Caio Lucas da Silva Chacon     - 20200025769
// Luiz Fernando Costa dos Santos - 20200025446

#include <stdio.h>

int barras_verticais(int x[], int y[], int len_x, int len_y) {
	int aux, maior=0, contador; 


	// maior -> achar o maior valor do array
	for (int k=0; k < len_y; k++) {
		if (y[k] > maior) {
			maior = y[k];
		}
	}


	// criando um array pra ordena-lo
	int y_sort[len_y];

	for (int j=0 ; j < len_y; j++) {
		y_sort[j] = y[j];	
	}
		

	// algoritmo de sort
	for (int c=0; c < len_y; c++) {
		for (int p=0; p < len_y; p++) {
			if (y_sort[p] > y_sort[p + 1]) {
                aux = y_sort[p];
                y_sort[p] = y_sort[p + 1];
                y_sort[p + 1] = aux;
			}	
		}
	}

	printf("\n");

	// for para printar os quadradinhos e os labels do eixo y
	contador = len_y-1;

	for (int quadradinho=maior-1; quadradinho >= 0; quadradinho-- ) {
		for (int espacos=0; espacos < (len_y+1); espacos++) {
			if (espacos == 0) {
				if (y_sort[contador] == quadradinho+1) {
					printf("%.2d |", y_sort[contador]);
					contador--;
				}else {
					printf("   |");
				}
			}else {	
				if (y[espacos-1] <= quadradinho) {
					printf("       ");
				} else {
					printf("   ■■  ");
				}
			}
		}
		printf("\n");
	}


	// for pra printar os labels do eixo x
	for (int i=0; i < len_y ; i++) {
		printf("--------");
	}
	printf("\n   |  ");
	for (int i=0; i < len_y ; i++) {
		printf("%d | ", x[i]);
	}
	printf("\n");

	return 0;
}
 
int barras_horizontais(int x1[], int y1[], int len_x1, int len_y1) {
	int aux, maior=0;

	// maior -> achar o maior valor do array
	for (int k=0; k < len_x1; k++) {
		if (x1[k] > maior) {
			maior = x1[k];
		}
	}

	printf("\n");

	// for para printar os quadradinhos e os labels do eixo y
	for (int j=0; j < len_x1; j++ ) {
		
		printf("%d |  ",y1[j]);

		for (int quadradinho=0; quadradinho < (int) x1[j]; quadradinho++) {
			printf("■ ");
		}
		printf("\n");
	}

	int x_sort[len_x1];

	for (int j=0 ; j < len_x1; j++) {
		x_sort[j] = x1[j];	
	}

	// algoritmo de sort
	for (int c=0; c < len_x1; c++) {
		for (int p=0; p < len_x1; p++) {
			if (x_sort[p] > x_sort[p + 1]) {
                aux = x_sort[p];
                x_sort[p] = x_sort[p + 1];
                x_sort[p + 1] = aux;
			}	
		}
	}
	
	// printar os tracinhos do eixo X
	printf("------------");
	for (int i=0; i < maior; i++) {
		printf("--");
	}


	// printar os labels do eixo X
	printf("\n     |");

	int item = 0;

	for (int i=0; i <= maior; i++) {
		if (i == x_sort[item]) {
			printf("%.2d", x_sort[item]);
			
			if (item < len_x1){
				item++;
			}

		}else {
			printf("  ");
		}	
	}
	

	printf("\n");

	return 0;
}
	 


int main(void){
	int array_1[] = {2017, 2018, 2019, 2020, 2021}; // valores padrão
	int array_2[] = {2, 4, 10, 6, 8}; // valores padrão

	int tam_1 = 5, tam_2 = 5; // tamanho dos arrays

	barras_verticais(array_1, array_2, tam_1, tam_2); 

	barras_horizontais(array_2, array_1, tam_2, tam_1);		
	
	return 0;
}
