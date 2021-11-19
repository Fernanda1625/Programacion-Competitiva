/*
Ejercicio 2: Se le da una cuadrícula de matriz binaria m x n, donde 0 representa una celda marina y 1
representa una celda terrestre. Un movimiento consiste en caminar de una celda de tierra a otra celda
de tierra adyacente (en 4 direcciones) o caminar fuera del límite de la cuadrícula. Devuelve el número
de celdas terrestres en la cuadrícula para las que no podemos salir del límite de la cuadrícula en ningún
número de movimientos. (https://leetcode.com/problems/number-of-enclaves/)

Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count = 0;
    int m,n;
    vector<vector<int>> direcciones = {{-1,0},{0,1},{0,-1},{1,0}};

    void helper(int row, int col, vector<vector<int>>& A){
        A[row][col] = -1; // cambiar el valor a -1 para evitar rehacer el trabajo.
        for(auto dir : direcciones){
            int r = row + dir[0];
            int c = col + dir[1];
            if(r>=0 && r<m && c>=0 && c<n){
                if(A[r][c]==1)
                    helper(r,c,A);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& A){
        m = (int)A.size();
        n = (int)A[0].size();
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if((row==0 || row==m-1 || col==0 || col==n-1) and A[row][col]) //cambiar todos los 1 conectados a los bordes a -1
                    helper(row,col,A);
            }
        }

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(A[row][col]==1)
                    count++;
            }
        }
        return count;
    }
};
