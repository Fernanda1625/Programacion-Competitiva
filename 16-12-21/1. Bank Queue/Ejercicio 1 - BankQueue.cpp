// Ejercicio 1: Bank Queue
// URL: https://open.kattis.com/problems/bank
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

struct Person{
    int money;
    int time;

    Person(int m, int w){
        money = m;
        time = w;
    }
};

// comparar a las personas por su dinero
bool compareMoney(const Person &a, const Person &b){
        return a.money >= b.money;
}

// poner a la persona en la cola,
// si el lugar de la persona y todos los lugares debajo de esta están ocupados,
// detiene el bucle, no puede servirle.
void queuePerson(vector<int> &v, Person c){
    int i = c.time;

    while( i >= 0 ){
        if( v[i] == 0 ){
            v[i] = c.money;
            return;
        }
        i--;
    }
}

int main(){
	// N = la cantidad de personas en la cola
	// T = el tiempo en minutos hasta que Oliver cierra el banco
	// ci = la cantidad de efectivo en coronas suecas
	// ti = el tiempo en minutos a partir de ahora
    int N, T, ci, ti;
    int sum = 0;
    int i = 0;

    cin >> N >> T;

    vector<int> bQueue(T);
    vector<Person> money;

    for( int i = 0; i < N; i++ ){
        cin >> ci >> ti;
        Person c(ci, ti);

		// agrega un nuevo elemento al final del vector, después de su último elemento actual. El contenido de c se copia al nuevo elemento
        money.push_back(c);
    }

	// ordena los elementos en el rango [primero, último) en orden ascendente
    sort(money.begin(), money.end(), compareMoney);

    // poner en la cola el tiempo de la persona con dinero
    while( i < money.size() ){
        queuePerson(bQueue, money[i]);
        i++;
    }

    // sirva a todos dentro de la bQueue
    for( int i = 0; i < bQueue.size(); i++ ){
        sum += bQueue[i];
    }
    
    // imprime la cantidad máxima de dinero que se puede obtener de las personas en la cola antes de que cierre el banco
    cout << sum;
    
    return 0; 
}
