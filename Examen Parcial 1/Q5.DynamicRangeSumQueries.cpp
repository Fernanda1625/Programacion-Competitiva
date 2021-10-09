// Pregunta 5: Procesar consultas q de los siguientes tipos: actualizar el valor en la posición k a u. ¿Cuál es la suma de los valores en el rango [a, b]?
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> t;

void add(int k, long long x) {
  while (k <= n) {
    t[k] += x;
    k += k & -k;
  }
}

long long sum(int k) {
  long long s = 0;
  while (k >= 1) {
    s += t[k];
    k -= k & -k;
  }
  return s;
}

long long sum(int a, int b) {
  return sum(b) - sum(a - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, r, a, b;
  cin >> n >> q;
  vector<long long> x(n);
  t = vector<long long>(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    add(i + 1, x[i]);
  }
  for (int i = 0; i < q; i++) {
    cin >> r >> a >> b;
    if (r == 1) {
      add(a, b - x[a - 1]);
      x[a - 1] = b;
    }
    else cout << sum(a, b) << "\n";
  }
}
