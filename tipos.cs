/* Uso:
		$ apt-get install mono-mcs
		$ mcs -out:porvalor tipos.cs 
		$ ./porvalor
*/
/*	Tipos por valor son tipos sencillos que almacenan un dato
	concreto y lo almacenan en el stack. Lo que se pasa a una 
	función como parámetro es una copia del dato.

	Tipos por referencia son todos los demas en concreto, 
	todas las clases de objetos, así como algunos tipos 
	primitivos que no tienen un tamanio determinado(como las
	cadenas). Se almacenan en el heap y lo que se pasa a una 
	función como parámetro no es una copia del dato, sino una 
	copia de la referencia al dato.(Un puntero) 
*/

using System;

public class Persona {
	public string Nombre;
	public string Apellidos;
	public int Edad;
}

class Tipos {

	static public int Suma2(int n){
		n = n + 2;
		return n;
	}

	static public void CambiaNombre(Persona per){
		per.Nombre = per.Nombre + " CAMBIADO";
	}

/*
	static void Main(){
//	Si pasamos un tipo por valor a una función y lo modificamos dentro 
//	de ésta, el valor original permanecerá inalterado al terminar la llamada.
//	Esto es debido a que los números enteros son tipos por valor y por lo 
//	tanto se pasa una copia de los mismos al stack de la función que se 
//	llama, no viéndose afectado el valor original.

		int i = 5;
		Console.WriteLine(Suma2(i));
		Console.WriteLine(i);
		Console.ReadLine();
	}
*/

/*
	static void Main(){
//	Sin embargo, si lo que le pasamos a la función es un objeto (por lo tanto, 
// 	un tipo por referencia), veremos que sí podemos modificar los datos originales.
//	Al declarar una variable de tipo Persona se genera una instancia de la misma
//	en el heap, es decir, ahora en el stack no se almacenan los datos en sí,
//	sino tan solo un “puntero” a los mismos. Es una forma indirecta de referirse a ellos.

		Persona p = new Persona();
		p.Nombre = "Antonio";
		p.Apellidos = "López";
		p.Edad = 27;

		CambiaNombre(p);
		Console.WriteLine(p.Nombre);
		Console.ReadLine();
	}
*/

}

/*
	En realidad el comportamiento de la pila es idéntico en ambos casos, 
	lo que cambia es la información que se almacena, que es el propio 
	dato en el caso de los tipos por valor, y la referencia al dato en 
	el caso de los tipos por referencia.
*/
