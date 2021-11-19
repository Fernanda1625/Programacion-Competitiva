/*
Ejercicio 4: Escribir un programa de análisis que cuente el número de estrellas visibles en
una imagen de mapa de bits. Para cada caso, muestre el número de caso seguido del número de
estrellas que son visibles en la imagen correspondiente. Siga el formato de la salida de muestra.
(https://open.kattis.com/problems/countingstars)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

struct pixel {
    char c;
    bool used;
};

int floodfill(int m, int n, int i, int j, vector<vector<pixel>>& v) {
    // Si está fuera de los límites
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }

    // Si ya se usó
    if(v[i][j].used) {
        return 0;
    }

    // Usar este punto
    v[i][j].used = true;

    // Usa todos los puntos adyacentes
    floodfill(m, n, i, j+1, v);
    floodfill(m, n, i, j-1, v);
    floodfill(m, n, i+1, j, v);
    floodfill(m, n, i-1, j, v);

    return 1;
}

int main() {
    int m, n;
    int count = 1;
    while(cin >> m && cin >> n) {
        vector<vector<pixel>> v;

        for(int i = 0; i < m; i++) {
            vector<pixel> temp;
            for(int i = 0; i < n; i++) {
                char c;
                cin >> c;
                pixel p;
                p.c = c;
                p.used = (c == '#');
                temp.push_back(p);
            }
            v.push_back(temp);
        }

        int stars = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                stars += floodfill(m, n, i, j, v);
            }
        }

        cout << "Case " << count << ": " << stars << endl;
        count++;
    }
}
