// Ejercicio 1.2: Escribe una funci�n que, dadas dos matrices A y B no vac�as que constan de N enteros, devuelve el n�mero de peces que permanecer�n vivos (https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/)
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    const size_t N = A.size();
    vector<int> pila;
    int muertos = 0;
    for (size_t i = 0; i < N; ++i) {
        if (B[i]) {
            pila.push_back(A[i]);
        } else {
            while (pila.size() && pila.back() < A[i]) {
                pila.pop_back();
                ++muertos;
            }
            if (pila.size()) {
                ++muertos;
            }
        }
    }
    return N-muertos;
}
