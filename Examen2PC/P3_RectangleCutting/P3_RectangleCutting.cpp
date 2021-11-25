// Problema 3: Rectangle Cutting
// URL: https://cses.fi/problemset/task/1744
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    vector <vector<int>> dp(a+1,vector<int> (b+1));

    for( int i = 0; i <= a; i++ ){
        for( int j = 0; j <= b; j++ ){

            //Caso base
            if(i == j) //cuando i==j, ya es un cuadrado, por lo que se necesitan 0 cortes.
            dp[i][j] = 0;
            
            else{
                dp[i][j] = INT_MAX;
                for(int k=1;k<i;k++)
                	dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]+1); // comprobar el mínimo posible entre todos los cortes posibles en i (horizontalmente)
                	
                for(int k=1;k<j;k++)
                	dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]+1); // comprobar el minimo posible entre todos los cortes posibles en j (verticalmente)
            }
        }
    }
    cout << dp[a][b] << endl;

    return 0;
}
