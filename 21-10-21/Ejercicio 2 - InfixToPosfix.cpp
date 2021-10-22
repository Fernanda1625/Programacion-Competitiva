// Ejercicio 2:  El programa debe convertir una expresión infija a su expresión posfija (https://www.urionlinejudge.com.br/judge/es/problems/view/1077)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

map<char,int> op;

void orden(){
	op['+']=1;
	op['-']=1;
	op['/']=2;
	op['*']=2;
	op['^']=3;
}

void infixToPostfix(string str){
	stack<char> pila;

	for( int i = 0; i < str.length(); i++ ){
		if(isalnum(str[i]))
      cout << str[i];

		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||
		str[i]=='^'){
			if(!pila.empty()){
			  while(op[str[i]] <=op [pila.top()]){
				  cout<<pila.top();
				  pila.pop();
				  if(pila.empty())
            break;
			  }
		  }
			pila.push(str[i]);
		}
		else if(str[i]=='('){
			pila.push('(');
		}
		else if(str[i]==')'){
			while(pila.top()!='('){
				cout << pila.top();
				pila.pop();
			}
			pila.pop();
		}
	}
	while(!pila.empty()){
		cout<<pila.top();
		pila.pop();
	}
	cout << endl;
}

int main(){
	orden();
	int N;
	cin >> N;
	cin.ignore();
	string str;
	while(N--){
		cin >> str;
		infixToPostfix(str);
	}
	return 0;
}
