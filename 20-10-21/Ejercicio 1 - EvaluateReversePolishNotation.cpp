// Ejercicio 1: Evalúe el valor de una expresión aritmética en notación polaca inversa (https://leetcode.com/problems/evaluate-reverse-polish-notation/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numeros;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (isdigit(s[0]) || s.size() > 1) {
                numeros.push(stoi(s));
                continue;
            }
            int a = numeros.top();
            numeros.pop();
            int b = numeros.top();
            numeros.pop();
            if (s == "+") {
                numeros.push(a+b);
            } else if (s == "-") {
                numeros.push(b-a);
            } else if (s == "*") {
                numeros.push(a*b);
            } else {
                numeros.push(b/a);
            }
        }
        return numeros.top();
    }
};
