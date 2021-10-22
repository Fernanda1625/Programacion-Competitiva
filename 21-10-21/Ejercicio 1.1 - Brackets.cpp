// Ejercicio 1-1: Escribe una función que, dada una cadena S que consta de N caracteres, devuelve 1 si S está correctamente anidado y 0 en caso contrario (https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    stack<char> pila;
    for (int i = 0; i < S.size(); ++i) {
        char c = S[i];
        if ('(' == c || '{' == c || '[' == c) {
            pila.push(c);
        } else {
            if (pila.empty()) return 0;
            char t = pila.top();

            if ('}' == c && '{' != t) return 0;
            if (']' == c && '[' != t) return 0;
            if (')' == c && '(' != t) return 0;
            pila.pop();
        }
    }
    if (pila.empty())
        return 1;
    else
        return 0;
}
