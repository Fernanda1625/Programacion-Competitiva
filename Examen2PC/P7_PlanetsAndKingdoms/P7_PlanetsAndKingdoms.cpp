// Problema 7: Planets and Kingdoms
// URL: https://cses.fi/problemset/task/1683
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, k, par[N], Time, num[N], low[N], cmp[N];
vector<int> g[N], s;

int Tarjan(int u) {
	num[u] = low[u] = ++Time;
  	s.emplace_back(u);
  	for ( int v: g[u] ) {
    	if (!cmp[v]) {
      		low[u] = min(low[u], num[v] ?: Tarjan(v));
    	}
  	}
  	if ( low[u] == num[u] ) {
    	int v; ++k;
    	do {
      		v = s.back(); s.pop_back();
      		cmp[v] = k;
    	} while ( v != u );
  	}
  	return low[u];
}

int main() {
	cin >> n >> m;
  	for  (int i = 1, u, v; i <= m; ++i ) {
    	cin >> u >> v;
    	g[u].emplace_back(v);
  	}
  	for (int i = 1; i <= n; ++i) {
    	if (!num[i])
			Tarjan(i);
  	}
  	cout << k << "\n";
  	for ( int i = 1; i <= n; ++i ) {
    	cout << cmp[i] << " \n"[i == n];
  	}
  	return 0;
}
