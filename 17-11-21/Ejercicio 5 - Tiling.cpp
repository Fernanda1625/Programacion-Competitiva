/*
Ejercicio 5: Dado un tablero "2 x n" y fichas de tamaño "2 x 1", cuente el número de
formas de colocar las fichas en el tablero dado utilizando las fichas de 2 x 1.
Un mosaico puede colocarse horizontalmente, es decir, como un mosaico de 1 x 2
o verticalmente, es decir, como un mosaico de 2 x 1.

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int obtenerNroFormas(int n){
    //Caso base
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return obtenerNroFormas(n - 1) + obtenerNroFormas(n - 2);
}

int main(){
	/*
	Caso de prueba 1:
		n = 4
		Numero de formas = 3
	Caso de prueba 2:
		n = 3
		Numero de formas = 2
	*/
	
    cout << "Caso de prueba 1:" << obtenerNroFormas(4) << endl;
    cout << "Caso de prueba 2:" << obtenerNroFormas(3);

    return 0;
}
