// Pregunta 1: Se proporciona uu arreglo A no vacío que consta de N números enteros. Un par de números enteros (P, Q), tales que 0 ≤ P <Q <N, se llama un segmento del arreglo A (observe que el segmento contiene al menos dos elementos). El promedio de una rebanada (P, Q) es la suma de A [P] + A [P + 1] + ... + A [Q] dividida por la longitud de la rebanada. Para ser precisos, el promedio es igual a (A [P] + A [P + 1] + ... + A [Q]) / (Q - P + 1).
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#ifdef debug
    #define LOG(X) cout << X << endl
#else
    #define LOG(X) (void) 0
#endif

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    vector<int> pre_sum(A.size() + 1, 0);

    for(size_t i=1; i<=A.size(); i++)
        pre_sum[i] = (pre_sum[i-1] + A[i-1]);
    
    double min_av = 20000;
    int min_ix = -1;
    for(size_t i=1; i<A.size(); i++){
        double avg = (pre_sum[i+1] - pre_sum[i-1]) / 2.0d;
        if(avg < min_av){
            min_ix = i-1;
            min_av = avg;
            LOG("min_av=" << min_av << ", min-ix=" << min_ix << " i=" << i);
        }
        if(i+2 < pre_sum.size()) {
            avg = (pre_sum[i+2] - pre_sum[i-1]) / 3.0d;
            if(avg < min_av)
            {
                min_ix = i-1;
                min_av = avg;
                LOG("min_av=" << min_av << ", min-ix=" << min_ix << " i=" << i);
            }   
        }
    }

    return min_ix;
}
