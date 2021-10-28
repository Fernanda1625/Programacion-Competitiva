// Ejercicio 3: Dado un número entero de arreglo nums y un número entero k, devuelve el k-ésimo elemento
// más grande de l arreglo. (https://leetcode.com/problems/kth-largest-element-in-an-array/)

// Curso: Programación Competitiva
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
