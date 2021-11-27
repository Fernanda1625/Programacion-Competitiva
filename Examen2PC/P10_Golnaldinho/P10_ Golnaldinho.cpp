// Problema 10: Golnadinho
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2792
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

#define MAX 500005

int modPow2(int n){
	return n & (-n);
}

void update(vector<int> &tree, int node, int v){
	while( node < MAX ){
		tree[node] += v;
		node += modPow2(node);
	}
}

int query(vector<int> &tree, int node){
	int sum = 0;

	while( node > 0 ){
		sum += tree[node];
		node -= modPow2(node);
	}
	return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    
	int N, input, i;

	cin >> N;

	vector<int> tree(MAX, 0);

	for( i = 1; i <= N; i++ ){
		cin >> input;
		cout << (input - query(tree, input));

		if (i == N )
			cout << endl;
		else
			cout << " ";

		update(tree, input, 1);
	}
	return 0;
}
