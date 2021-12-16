// Ejercicio 4: Bachet's Game
// URL: https://open.kattis.com/problems/bachetsgame
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while( cin >> n >> m ){

        vector<int> v;

        vector<bool> numbers(n,false);

        for( int i = 0; i < m; ++i ){
            int j;
            cin >> j;
            v.push_back(j);
            numbers[j-1] = true;        
        }
        for( auto it = numbers.begin(); it != numbers.end(); ++it){
            if(!(*it)){
                for(auto it2 = v.begin(); it2 != v.end(); ++it2){      
                    if(it + *it2 < numbers.end()){                    
                    auto pos = *(it + *it2);
                    pos = true;
                    }
                }
            }
        }
       if(numbers[n-1]){                                              
           cout << "Stan wins" << endl;
       } else {
           cout << "Ollie wins" << endl;
       }
    }
    return 0;
}
