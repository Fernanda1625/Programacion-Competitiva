// Ejercicio 1.4: Escribe una función que, dada una matriz H de N números enteros positivos que especifican la altura del muro, devuelve el número mínimo de bloques necesarios para construirlo (https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &H) {
  stack<int> pila;
    int alturaActual = 0;
    int ladrillosUsados = 0;

    for (auto elem : H){
        while (elem < alturaActual){
            const int ultimaBase = pila.top();
            pila.pop();
            alturaActual -= ultimaBase;
        }

        if (elem > alturaActual)
        {
            const int diff = elem - alturaActual;
            pila.push(diff);
            ++ladrillosUsados;
            alturaActual = elem;
        }
    }

    return ladrillosUsados;
}
