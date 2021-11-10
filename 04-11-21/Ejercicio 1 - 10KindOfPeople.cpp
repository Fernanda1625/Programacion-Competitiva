// Ejercicio 1: Para cada consulta, genere un binario si un usuario binario puede comenzar desde la ubicaci�n
// r1, c1 y moverse a la ubicaci�n r2, c2. Salida decimal si un usuario decimal puede moverse entre las dos
// ubicaciones. De lo contrario, no env�e ninguno. (https://open.kattis.com/problems/10kindsofpeople)

// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& disjoint, int a) {
    if(disjoint[a] == -1) {
        return a;
    }

    disjoint[a] = find(disjoint, disjoint[a]);
    return disjoint[a];
}

void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}

bool inrange(int x, int y, int ti, int tj) {
    if(ti < 0) {
        return false;
    }
    if(tj < 0) {
        return false;
    }

    if(ti >= x) {
        return false;
    }
    if(tj >= y) {
        return false;
    }
    return true;
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> zones;
    zones.resize(x, vector<int>(y));

    // Tomar en mapa
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            char val;
            cin >> val;
            zones[i][j] = val - '0';
        }
    }

    // Construir conjunto disjunto
    vector<int> disjoint;
    disjoint.resize(x * y, -1);
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            int ti, tj;

            ti = i-1;
            tj = j;
            if(inrange(x, y, ti, tj) && zones[i][j] == zones[ti][tj]) {
                join(disjoint, i*y+j, ti*y+tj);
            }

            ti = i;
            tj = j-1;
            if(inrange(x, y, ti, tj) && zones[i][j] == zones[ti][tj]) {
                join(disjoint, i*y+j, ti*y+tj);
            }

            ti = i+1;
            tj = j;
            if(inrange(x, y, ti, tj) && zones[i][j] == zones[ti][tj]) {
                join(disjoint, i*y+j, ti*y+tj);
            }

            ti = i;
            tj = j+1;
            if(inrange(x, y, ti, tj) && zones[i][j] == zones[ti][tj]) {
                join(disjoint, i*y+j, ti*y+tj);
            }

        }
    }

    // Ejecuta todas las consultas
    int queries;
    cin >> queries;
    while(queries--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;

        if(find(disjoint, x1*y+y1) == find(disjoint, x2*y+y2)) {
            if(zones[x1][y1] == 1) {
                cout << "decimal" << endl;
            }
            else {
                cout << "binary" << endl;
            }
        }
        else {
            cout << "neither" << endl;
        }
    }
}
