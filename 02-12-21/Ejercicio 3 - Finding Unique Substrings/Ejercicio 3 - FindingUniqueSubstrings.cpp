// Ejercicio 3: Finding Unique Substrings
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

struct suffix {
  int index;
  int R[2];
};

int comp(suffix a, suffix b) {
  return (a.R[0] == b.R[0]) ?
    (a.R[1] < b.R[1] ? 1 : 0) :
    (a.R[0] < b.R[0] ? 1 : 0);
}

vector <int> build(string txt, int n) {
  suffix suffixes[n];
  int i, j;

  for ( i = 0; i < n; i++ ) {
    suffixes[i].index = i;
    suffixes[i].R[0] = txt[i] - 'A';
    suffixes[i].R[1] = ((i + 1) < n) ?
      (txt[i + 1] - 'a') : -1;
  }

  sort(suffixes, suffixes + n, comp);

  int ind[n];
  for ( j = 4; j < 2 * n; j = j * 2 ) {
    int R = 0;
    int prev_R = suffixes[0].R[0];
    suffixes[0].R[0] = R;
    ind[suffixes[0].index] = 0;

    for ( i = 1; i < n; i++ ) {
      if ( suffixes[i].R[0] == prev_R && suffixes[i].R[1] == suffixes[i - 1].R[1] ) {
        prev_R = suffixes[i].R[0];
        suffixes[i].R[0] = R;
      } else {
          prev_R = suffixes[i].R[0];
          suffixes[i].R[0] = ++R;
      }
      ind[suffixes[i].index] = i;
    }

    for ( i = 0; i < n; i++ ) {
      int nextidx = suffixes[i].index + j / 2;
      suffixes[i].R[1] = (nextidx < n) ?
        suffixes[ind[nextidx]].R[0] : -1;
    }
    sort(suffixes, suffixes + n, comp);
  }

  vector <int> sa;
  for (i = 0; i < n; i++)
    sa.push_back(suffixes[i].index);

  return sa;
}

vector <int> kasai(string txt, vector <int> sa) {
  int n = sa.size();

  vector < int > lcp(n, 0);

  vector <int> inverseSuff(n, 0);
  int i, j;
  for ( i = 0; i < n; i++ )
    inverseSuff[sa[i]] = i;

  int k = 0;

  for ( i = 0; i < n; i++ ) {
    if ( inverseSuff[i] == n - 1 ) {
      k = 0;
      continue;
    }

    int j = sa[inverseSuff[i] + 1];

    while ( i + k < n && j + k < n && txt[i + k] == txt[j + k] )
      k++;

    lcp[inverseSuff[i]] = k;

    if ( k > 0 )
      k--;
  }

  return lcp;
}

int countUniqueSubstring(string txt) {
  int n = txt.length();

  vector <int> sa = build(txt, n);
  vector <int> lcp = kasai(txt, sa);

  int result = n - sa[0];

  for ( int i = 1; i < lcp.size(); i++ )
    result += (n - sa[i]) - lcp[i - 1];

  result++;
  return result;
}

int main() {
  // Caso de prueba 1:
        // entrada string = AZAZA
        // salida = 9 -> A, AZ, AZA, AZAZ, AZAZA, Z, ZA, ZAZ, ZAZA
  string str = "AZAZA";
  // cin >> str;
  cout << countUniqueSubstring(str);
  return 0;
}
