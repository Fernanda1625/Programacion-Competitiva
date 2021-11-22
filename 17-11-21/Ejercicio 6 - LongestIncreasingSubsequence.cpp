/*
Ejercicio 6: Dada una matriz de enteros nums, devuelve la longitud de la subsecuencia estrictamente
creciente más larga. Una subsecuencia es una secuencia que se puede derivar de una matriz eliminando
algunos o ningún elemento sin cambiar el orden de los elementos restantes. Por ejemplo, [3,6,2,7] es
una subsecuencia de la matriz [0,3,1,6,2,2,7]. (https://leetcode.com/problems/longest-increasing-subsequence/)


Curso: Programación Competitiva
Grupo: A
Alumna: Fernanda Anthoanette Paredes Escobedo
CUI: 20182906
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                /*
                antes de nums [i], agregue la subsecuencia creciente que termina en j
                */
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
