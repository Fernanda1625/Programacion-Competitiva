// Ejercicio 3: Dado un n�mero entero de arreglo nums y un n�mero entero k, devuelve el k-�simo elemento
// m�s grande de l arreglo. (https://leetcode.com/problems/kth-largest-element-in-an-array/)

// Curso: Programaci�n Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int numero: nums){
            pq.push(numero);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
