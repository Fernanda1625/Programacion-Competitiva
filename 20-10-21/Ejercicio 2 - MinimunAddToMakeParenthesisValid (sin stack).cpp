// Ejercicio 2: Devuelve el número mínimo de movimientos necesarios para que s (una cadena con paréntesis) sea válido (https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

class Solution {
public:
    int minAddToMakeValid(String s) {
        int respuesta = 0;
        int balance = 0;
        for(int i = 0; i < s.length(); i++) {
            (s[i]=='(') ? balance++ : balance--;
            if(balance == -1) {
                balance = 0;
                respuesta ++;
            }
        }
        return respuesta + balance;
    }
};
