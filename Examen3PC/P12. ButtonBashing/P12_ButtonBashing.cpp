// Problema 12: Button Bashing
// URL: https://open.kattis.com/problems/buttonbashing
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

const int iinf = 1e9 + 10;

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int n, m;
        cin >> n >> m;

        vector<int> move(n);
        for(auto& i : move) {
            cin >> i;
        }

        vector<int> dist(3601, iinf);
        dist[0] = 0;

        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto& i : move) {
                int next = curr + i;
                next = max(0,next);
                next = min(3600,next);

                if(dist[next] > dist[curr]+1) {
                    dist[next] = dist[curr]+1;
                    q.push(next);
                }
            }
        }

        for(int i = m; i <= 3600; i++) {
            if(dist[i] != iinf) {
                cout << dist[i] << " " << i - m << endl;
                break;
            }
        }
    }

    return 0;
}
