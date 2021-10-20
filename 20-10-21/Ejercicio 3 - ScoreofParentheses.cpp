// Ejercicio 3: Dada una cadena de paréntesis balanceada s, devuelve la puntuación de la cadena (https://leetcode.com/problems/score-of-parentheses/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> numeros;
        stack<char> operador,pila;
        for(int i = 0; i < s.length(); i++){
        	char temporal = s[i];
        	if(temporal == '(') {
				pila.push(temporal);
				if(i-1 >= 0 && s[i-1] == '(')
                    operador.push('*');
				else if(i-1 >= 0 && s[i-1] == ')')
                    operador.push('+');
			}
        	else if(temporal == ')' && pila.top() == '('){
        		pila.pop();
        		if(i-1 >= 0 && s[i-1] =='(') {
					numeros.push(1);
					while(!operador.empty() && operador.top() == '+'){
						int a = numeros.top();
						numeros.pop();
						int b = numeros.top();
						numeros.pop();
						numeros.push(a+b);
						operador.pop();
					}
				}
        		else {
        			if(operador.top()=='*') {
						int a = numeros.top();
						numeros.pop();
						numeros.push(2*a);
						operador.pop();
					}
					while(!operador.empty() && operador.top() == '+'){
						int a = numeros.top();
						numeros.pop();
						int b = numeros.top();
						numeros.pop();
						numeros.push(a+b);
						operador.pop();
					}
				}
			}
		}
		return numeros.top();
    }
};
