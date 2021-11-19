/*
Ejercicio 7: Hay una isla rectangular de m x n que limita con el Oc�ano Pac�fico y el Oc�ano Atl�ntico.
El Oc�ano Pac�fico toca los bordes izquierdo y superior de la isla, y el Oc�ano Atl�ntico toca los bordes
derecho e inferior de la isla. La isla est� dividida en una cuadr�cula de celdas cuadradas. Se le da una
altura de matriz entera de m x n donde las alturas [r] [c] representan la altura sobre el nivel del mar
de la celda en la coordenada (r, c). La isla recibe mucha lluvia y el agua de lluvia puede fluir a las celdas
vecinas directamente al norte, sur, este y oeste si la altura de la celda vecina es menor o igual que la altura
de la celda actual. El agua puede fluir desde cualquier celda adyacente a un oc�ano hacia el oc�ano. Devuelve una
lista 2D de resultados de coordenadas de cuadr�cula donde resultado [i] = [ri, ci] denota que el agua de lluvia
puede fluir desde la celda (ri, ci) hacia los oc�anos Pac�fico y Atl�ntico. (https://leetcode.com/problems/pacific-atlantic-water-flow/)

Curso: Programaci�n Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>result;
    int n;
    int m;

    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int prev_val){
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<prev_val or ocean[i][j]){
            return;
        }
        ocean[i][j] = true;
        dfs(i-1,j,matrix,ocean,matrix[i][j]);
        dfs(i+1,j,matrix,ocean,matrix[i][j]);
        dfs(i,j-1,matrix,ocean,matrix[i][j]);
        dfs(i,j+1,matrix,ocean,matrix[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(not matrix.size() or not matrix[0].size()){
            return result;
        }
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<bool>> pacific( n , vector<bool> (m, false));
        vector<vector<bool>> atlantic( n , vector<bool> (m, false));

        for(int i = 0; i < n;i++){
            dfs(i,0,matrix,pacific,INT_MIN);
            dfs(i,m-1,matrix,atlantic,INT_MIN);
        }

        for(int j = 0; j < m ; j++){
            dfs(0,j,matrix,pacific,INT_MIN);
            dfs(n-1,j,matrix,atlantic,INT_MIN);
        }

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back(vector<int>{i,j});
                }
            }
        }
        return result;
    }
};
