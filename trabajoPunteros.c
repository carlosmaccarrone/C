// El seguimiento de éste programa ayuda a entender como se manipula
// y trabaja con punteros. 
#include <stdio.h>

void incrementar(int *);
void cruzarPunteros(int *, int *);

void main(){
	int a, b, c, *p, *q, *r;

	p=&a;
	q=&b;
	*q=40;
	c=1;

	printf("B:%d\nDireccion B:%d\nQ:%d\nDireccion Q:%d\n", b, &b, q, &q);
	printf("Valor contenido en la direccion almacenada en Q:%d\n", *q);
	printf("------------------\n");

	printf("Indique el valor A: ");
	scanf("%d", p);

	printf("A:%d\nDireccion A:%d\nP:%d\nDireccion P:%d\n", a, &a, p, &p);
	printf("Valor contenido en la direccion almacenada en P:%d\n", *p);
	printf("------------------\n");

	r=&a;
	*r=200;

	printf("A:%d\nDireccion A:%d\nP:%d\nDireccion P:%d\n", a, &a, p, &p);
	printf("Valor contenido en la direccion almacenada en P:%d\n", *p);
	printf("R:%d\nDireccion R:%d\nValor contenido en la direccion almacenada en R:%d\n", r, &r, *r);
	printf("------------------\n");

	if(*p==*q) printf("El valor del puntero p es igual al valor del puntero q\n");
	if(*p==*r) printf("El valor del puntero p es igual al valor del puntero r\n");

	incrementar(&c);
	printf("C incrementado:%d\n", c);

	printf("Valores antes de cruzarse\t A:%d\tB:%d\n", a, b);
	cruzarPunteros(&a, &b);
	printf("Valores despues de cruzarse\t A:%d\tB:%d\n", a, b);
}

void incrementar(int *val){
	while(*val<10){
		(*val)++;
	}
}

void cruzarPunteros(int *valor1, int *valor2){
	int swapValor;
	swapValor = *valor1;
	*valor1 = *valor2;
	*valor2 = swapValor;
}
