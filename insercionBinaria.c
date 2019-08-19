#include <stdio.h>		// printf()
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time() para inicializar srand()

#define NELEM(x) (sizeof(x) / sizeof((x)[0]) - 1)

void main(){
	int i, j, array[32] = {0};

	srand(time(NULL));	
	/* 
		srand() establece la semilla para el generador de 
		números aleatorios, sin srand, rand generará solo 
		una vez números aleatorios, el uso de time significa 
		que la secuencia de números generada es "al azar".
		El puntero null es un puntero que intencionalmente 
		apunta a nada.
	*/

	for( i=0 ; i<=NELEM(array) ; i++ ){
		array[i] = 1 + rand() % 999; 	
		/* 
			Genera un valor único y aleatorio 
			de hasta 999, para cada elemento.
		*/
	}

	for(i=0;i<=31;i++){
		printf("%d  ", array[i]);	// Vista del valor de cada elemento.
	}
	putchar('\n');
	putchar('\n');

	/* 
		Se crea una variable para almacenar valores temporales
		para que el algoritmo ejecute la ordenación.
	*/
	int temp;

	for( i=1 ; i<=NELEM(array) ; i++ ){
		j = i;
		temp = array[j];
		while( j>0 && temp<array[j-1] ){
			array[j]=array[j-1];
			j--;
		}
		array[j] = temp;
	}
		/*
			El tiempo de ejecución del algoritmo es proporcional a n^2.
			Siendo n el número de elementos totales, es un algoritmo
			estable, solo requiere la variable temp, pero el método
			efectúa el menor número de comparaciones cuando el array 
			está totalmente desordenado y el máximo cuando está ordenado.
		*/

	for( i=0 ; i<=NELEM(array) ; i++ ){
		printf("%d  ", array[i]);	// Vista del valor de cada elemento.
	}
	putchar('\n');

}

/*
	Éste es un algoritmo de ordenamiento líneal que recurre 
	a una búsqueda binaria en lugar de una búsqueda secuencial 
	para insertar un elemento en la parte de arriba del array,
	que ya se encuentra ordenado

	Mientras que en una búsqueda secuencial se necesitan k
	comparaciones para insertar un elemento, en éste 
	procedimiento se necesitan k/2 comparaciones. Pero,
	en promedio hace númerosas comparaciones si se lo
	contrasta con los algoritmos de ordenamiento recursivo 
	como el MergeSort o el QuickSort.
*/