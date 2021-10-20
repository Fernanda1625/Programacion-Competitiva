// Ejercicio 2: Devuelve el número mínimo de movimientos necesarios para que s (una cadena con paréntesis) sea válido (https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

class Solution {
public:
    int minAddToMakeValid(string S) {
        int respuesta = 0;
        stack<int> pila;
        for(int i = 0; i < S.size();i++ ){
            if(S[i] == '(')
                pila.push(i);
            else if(pila.empty())
                respuesta++;
            else
                pila.pop();
        }
        respuesta += pila.size();
        return respuesta;
    }
};
