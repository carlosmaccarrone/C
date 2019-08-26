using System;

/*
	Boxing consiste en hacer que el compilador se vea forzado a 
	convertir un tipo por valor en un tipo por referencia, y por 
	tanto a almacenarlo en el heap en lugar de en el stack.
	Las operaciones de boxing y unboxing tienen un impacto en 
	el rendimiento y en la gestión de la memoria. El manejo de 
	valores en el stack es más rápido y eficiente que en el heap.
*/

class Box {

	void Main(){
		int num = 1;
		object obj = num;
//	Asignamos un tipo por valor a una variable pensada para almacenar un 
//	tipo por referencia. En este caso object es la clase base de todas las 
//	demás, así que se le puede asignar cualquier elemento(compatibilidad).

//	En el ejemplo dado que num es un tipo por valor y obj es un tipo por 
//	referencia, para hacer la asignación, el compilador se ve forzado 
//	a convertir uno en el otro. Lo que tendríamos al final es un nuevo 
//	objeto en el heap almacenando el valor original (1 en este caso) y 
//	en el stack habría una referencia a este objeto.

//	Esta operación se llama Boxing, porque es como envolver al valor en una 
//	caja para poder llevarlo cuidadosamente al heap y referenciarlo 
//	desde el stack.
	}
}

class UnBox {
	static void Main(){
		int num = 1;
		object obj = num;
		int num2 = (int) obj;
//	UnBoxing se produce cuando el tipo por referencia se convierte o 
//	asigna a un tipo por valor nuevo. Al forzar la conversión de obj 
//	en un tipo por valor, provocamos deshacer el boxing.
//	Ésto es útil cuando por ejemplo tenemos que llamar a una función 
//	o clase que acepta objetos como argumentos, pero necesitamos 
//	pasarle tipos por valor.
	}
}

/* 	Uso:
		$ apt-get install mono-mcs
		$ mcs -out:box box.cs 
		$ ./box
*/