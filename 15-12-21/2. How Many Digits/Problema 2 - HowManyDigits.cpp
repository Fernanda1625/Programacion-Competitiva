// Ejercicio 2: How Many Digits?
// URL: https://open.kattis.com/problems/howmanydigits
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
    double arr[1000001];
    arr[0] = 0;
    for ( int x = 1; x <= 1000000; x++ )
        arr[x] = arr[x - 1] + log10(x);
    int num;
    while (cin >> num)
        cout << (int)arr[num] + 1 << '\n';
    return 0;
}
