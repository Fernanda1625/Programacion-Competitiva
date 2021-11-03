// Ejercicio 4: Una isla es una región de tierra donde cada celda de la cuadrícula de la isla está
// conectada entre sí por algún camino, y cada tramo del camino solo sube, baja, izquierda o derecha.
// Dada una imagen, determine el número mínimo de islas que sea consistente con la imagen dada. (https://open.kattis.com/problems/islands3)

// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

char arr[101][101];
bool visited[101][101];

void dfs(int i, int j, int m, int n){
    if(!(i < 0 || j < 0 || i >= m || j>=n || arr[i][j]=='W' || visited[i][j]==true)){
        visited[i][j] = true;

        dfs(i+1,j,m,n);
        dfs(i,j+1,m,n);
        dfs(i-1,j,m,n);
        dfs(i,j-1,m,n);
    }
}

int main(){
    int i,j,m,n;

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int count = 0;

    for(int x = 0; x<n; x++){
        for(int y = 0; y<m; y++){
            if(arr[x][y] == 'L' && visited[x][y]==false){
                count++;
                dfs(x,y,n,m);
            }
        }
    }

  	cout << count;

    return 0;
}
