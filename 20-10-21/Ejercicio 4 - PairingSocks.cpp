// Ejercicio 4: Determinar la menor cantidad de movimientos que necesita para emparejar los calcetines, si es que es posible (https://open.kattis.com/problems/pairingsocks)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v1(2*n), v2;
    for(auto& i : v1) {
        cin >> i;
    }

    int moves = 0;
    while(!v1.empty()) {
        moves++;

        if(v2.empty()) {
            v2.push_back(v1.back());
            v1.pop_back();
            continue;
        }

        if(v1.back() == v2.back()) {
            v1.pop_back();
            v2.pop_back();
            continue;
        }

        v2.push_back(v1.back());
        v1.pop_back();
    }

    if(v2.empty()) {
        cout << moves << endl;
    }
    else {
        cout << "impossible" << endl;
    }
    return 0;
}
