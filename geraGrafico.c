// Caio Lucas da Silva Chacon     - 20200025769
// Luiz Fernando Costa dos Santos - 20200025446

#include <stdio.h>

void barras_verticais(int x[], int y[]) {
	int aux, maior=0, contador=4; // pra usar na func maior

	// maior -> achar o maior valor do array
	for (int k=0; k < 5; k++) {
		if (y[k] > maior) {
			maior = y[k];
		}
	}


	// criando um array pra ordena-lo
	int y_sort[5];

	for (int j=0 ; j < 5; j++) {
		y_sort[j] = y[j];	
	}
		

	// algoritmo de sort
	for (int c=0; c < 5; c++) {
		for (int p=0; p < 5; p++) {
			if (y_sort[p] > y_sort[p + 1]) {
                aux = y_sort[p];
                y_sort[p] = y_sort[p + 1];
                y_sort[p + 1] = aux;
			}	
		}
	}


	printf("\n");
	// for para printar os quadradinhos e os labels do eixo y
	for (int quadradinho=maior-1; quadradinho >= 0; quadradinho-- ) {
		for (int espacos=0; espacos < 6; espacos++) {
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
	printf("---|------------------------------------\n   |  ");
	for (int i=0; i< 5 ; i++) {
		printf("%d | ", x[i]);
	}
	printf("\n");
}
 
void barras_horizontais(int x[], int y[]) {
	int aux, maior=0; // pra usar na func maior

	// maior -> achar o maior valor do array
	for (int k=0; k < 5; k++) {
		if (x[k] > maior) {
			maior = x[k];
		}
	}

	printf("\n");

	// for para printar os quadradinhos e os labels do eixo y
	for (int j=0; j < 5; j++ ) {
		
		printf("%d |  ",y[j]);

		for (int quadradinho=0; quadradinho < (int) x[j]; quadradinho++) {
			printf("■ ");
		}
		printf("\n");
	}


	// algoritmo de sort
	for (int c=0; c < 5; c++) {
		for (int p=0; p < 5; p++) {
			if (x[p] > x[p + 1]) {
                aux = x[p];
                x[p] = x[p + 1];
                x[p + 1] = aux;
			}	
		}
	}
	
	// printar os tracinhos do eixo X
	printf("-----|------");
	for (int i=0; i < maior; i++) {
		printf("--");
	}


	// printar os labels do eixo X
	printf("\n     |  ");
	for (int i=0; i < maior; i++) {
		if (i+1 == x[0]) {
			printf("%.2d", x[0]);		
		} else if (i+1 == x[1]) {
			printf("%.2d", x[1]);		
		} else if (i+1 == x[2]) {
			printf("%.2d", x[2]);		
		} else if (i+1 == x[3]) {
			printf("%.2d", x[3]);		
		} else if (i+1 == x[4]) {
			printf("%.2d", x[4]);		
		} else {
			printf("  ");
		}

	}

	printf("\n");
}
	    
int main(void){
	int array_1[] = {2017, 2018, 2019, 2020, 2021}; // valores padrão
	int array_2[] = {6, 4, 12, 10, 8}; // valores padrão

	barras_verticais(array_1, array_2);
	barras_horizontais(array_2, array_1);
	
	return 0;
}