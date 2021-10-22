// Ejercicio 1.3: Escribe una función que, dada una cadena S que consta de N caracteres, devuelve 1 si la cadena S está correctamente anidada y 0 en caso contrario (https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    vector<char> pila;
    for(auto& caracter : S){
        if(caracter == '(') pila.push_back('(');
        else if(!pila.empty()) pila.pop_back();
        else return 0;
    }

    if(!pila.empty()) return 0;
    return 1;
}
