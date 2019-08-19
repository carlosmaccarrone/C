#include <stdio.h>
#include <string.h>

void main(void){
	char cadena[32], *cadena_ptr;
	int i, NCARAC;

	printf("Escriba una palabra: ");
	fgets(cadena, 32, stdin);

	NCARAC = strlen(cadena);
	cadena_ptr = &cadena[NCARAC];

	printf("La palabra escrita al revez es: ");
	for( i=0 ; i<=NCARAC ; i++){
		putchar(*cadena_ptr);
		cadena_ptr--;
	}
	putchar('\n');
}

/*
	Éste programa recorre al revés una cadena 
	(que puede o no contener espacios) a través
	de un puntero y lo va imprimiendo.
*/