/*
Ejercicio 6: Para cada caso de prueba, imprima un número entero: el número mínimo de saltos
que Gregory necesita para llegar al cuadrado con su amada delicadeza. Si no es posible llegar
a ese cuadrado, escriba la palabra "imposible" en su lugar. (https://open.kattis.com/problems/grasshopper)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

int INF = (1 << 31);

bool inrange(int w, int h, int x, int y) {
    return (x >= 0 && y >= 0 && x < w && y < h);
}

int main() {
    int x, y, startx, starty, endx, endy;
    while(cin >> x && cin >> y && cin >> startx && cin >> starty && cin >> endx && cin >> endy) {
        vector<vector<int>> v;
        v.resize(x, vector<int>(y, INF));

        v[startx-1][starty-1] = 0;

        queue<pair<int, int>> q;
        q.push({startx-1, starty-1});

        while(!q.empty()) {
            int currx = q.front().first;
            int curry = q.front().second;
            int currval = v[currx][curry];
            q.pop();

            vector<pair<int, int>> modificadores;
            modificadores.push_back({-2, -1});
            modificadores.push_back({-1, -2});
            modificadores.push_back({+2, -1});
            modificadores.push_back({+1, -2});
            modificadores.push_back({-2, +1});
            modificadores.push_back({-1, +2});
            modificadores.push_back({+2, +1});
            modificadores.push_back({+1, +2});

            for(auto m : modificadores) {
                if(inrange(x, y, currx+m.first, curry+m.second) && v[currx+m.first][curry+m.second] == INF) {
                    v[currx+m.first][curry+m.second] = currval+1;
                    q.push({currx+m.first, curry+m.second});
                }
            }
        }

        if(v[endx-1][endy-1] == INF) {
            cout << "impossible" << endl;
        }
        else {
            cout << v[endx-1][endy-1] << endl;
        }
    }
}
