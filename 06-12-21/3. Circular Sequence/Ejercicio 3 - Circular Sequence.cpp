// Ejercicio 3: Circular Sequence
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4459
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int MinExp( const char *s, const int slen ) {
	int i = 0, j = 1, k = 0, x, y, tmp;
	while( i < slen && j < slen && k < slen ) {
		x = i + k;
		y = j + k;
		if( x >= slen )
			x -= slen;
		if( y >= slen )
			y -= slen;
		if( s[x] == s[y] ) {
			k++;
		} else if( s[x] > s[y] ) {
			i = j+1 > i+k+1 ? j+1 : i+k+1;
			k = 0;
			tmp = i, i = j, j = tmp;
		} else {
			j = i+1 > j+k+1 ? i+1 : j+k+1;
			k = 0;
		}
	}
	return i;
}

int main() {
	int testcase, n;
	char s[100005];
	cin >> testcase;
	while(testcase--) {
		cin >> s;
		int pos = MinExp(s, strlen(s));
		for	(int i = pos; s[i]; i++)
			putchar(s[i]);
		for	(int i = 0; i < pos; i++)
			putchar(s[i]);
		puts("");
	}
	return 0;
}
