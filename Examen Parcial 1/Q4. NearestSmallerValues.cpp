// Pregunta 4: Encuentre para cada posición del arreglo la posición más cercana a su izquierda que tiene un menor valor
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main() {
  int n, x, y;
  cin >> n;
  vector<int> a(n);
  vector<tuple<int, int>> b;
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    while (!b.empty()) {
      tie(x, y) = b.back();
      if (y < a[i]) break;
      b.pop_back();
    }
    if (b.empty()) x = 0;
    cout << x << " \n"[i == n - 1];
    b.push_back({i + 1, a[i]});
  }

  return 0;
}
