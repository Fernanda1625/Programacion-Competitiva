// Ejercicio 1: Growling Gears
// URL: https://open.kattis.com/problems/growlinggears
// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for( int i = 0; i < n; i++ ) {
        int m;
        cin >> m;

        vector<double> v;

        for( int j = 0; j < m; j++ ) {
            double a, b, c;
            cin >> a >> b >> c;

            double pos = b / (2 * a);

            double val = a * pow(pos, 2) + b * pos + c;
            v.push_back(val);
        }

        int max = 0;
        for( int j = 0; j < m; j++ ) {
            if(v[j] > v[max]) {
                max = j;
            }
        }

        cout << max+1 << endl;
    }
}
