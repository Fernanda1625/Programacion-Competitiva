/*
Ejercicio 10: Se le entregará un mapa de Soteholm como N * M. Cada cuadrado de la cuadrícula
tiene una longitud de lado de 1 km y es agua o tierra. Su objetivo es calcular la longitud total
de la costa del mar de todas las islas. La costa del mar son todas las fronteras entre la tierra
y el mar, y el mar es cualquier agua conectada a un borde del mapa solo a través del agua. Dos
cuadrados están conectados si comparten un borde. Puede suponer que el mapa está rodeado de mar.
Los lagos e islas en los lagos no contribuyen a la costa del mar. (https://open.kattis.com/problems/coast)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int count(vector<vector<char>>& v, int i, int j) {
    int total = 0;
    if(v[i+1][j] == 's') {
        total++;
    }
    if(v[i-1][j] == 's') {
        total++;
    }
    if(v[i][j+1] == 's') {
        total++;
    }
    if(v[i][j-1] == 's') {
        total++;
    }
    return total;
}

bool untouched(vector<vector<char>>& v, int i, int j, int m, int n) {
    if(i < 0 || j < 0 || i >= m+2 || j >= n+2) {
        return false;
    }
    if(v[i][j] != '0') {
        return false;
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> v;
    v.resize(m+2, vector<char>(n+2, '0'));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0,0});

    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(v[i][j] != '0') {
            continue;
        }

        v[i][j] = 's';

        if(untouched(v, i+1, j, m, n)) {
            q.push({i+1, j});
        }
        if(untouched(v, i-1, j, m, n)) {
            q.push({i-1, j});
        }
        if(untouched(v, i, j+1, m, n)) {
            q.push({i, j+1});
        }
        if(untouched(v, i, j-1, m, n)) {
            q.push({i, j-1});
        }
    }

    int total = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(v[i][j] == '1') {
                total += count(v, i, j);
            }
        }
    }
    cout << total << endl;
}

