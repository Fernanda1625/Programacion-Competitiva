// Pregunta 10: Enfurecido por la derrota de los Decepticons después de una larga batalla épica con los Autobots, Megatron, en su rabia, ha decidido destruir todos los planetas en su camino de regreso a Cybertron desde la Tierra. Hay varios planetas entre la Tierra y Cybertron, y cada planeta tiene una cierta cantidad de Autobots para protegerlo de él. Dado que Megatron tiene poca munición, quiere luchar contra la menor cantidad posible de autobots en su camino de regreso. No puede derrotar a más de "M" autobots en total.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[50001];

int main() {
	int t;
	cin >> t;
	while(t--){
		int n,p=0,steps=0,minsteps=0;
		long long int b,sum=0,minpeople=1000001;
		cin >> n >> b;
		for(int i=0;i<n;i++){
			cin >> a[i];		
    }
		for(int i=0;i<n;i++){
			if(sum+a[i]<=b){
				sum+=a[i];
				steps++;
			}
			else{
				sum+=a[i];
				steps++;
				while(sum>b){
					sum-=a[p];
					steps--;
					p++;
				}
			}
			if(minsteps<steps){
				minsteps=steps;
				minpeople=sum;
			}
			else if(minsteps==steps){
				if(minpeople>sum){
					minpeople=sum;
				}
			}
		}
		printf("%lld %d\n",minpeople,minsteps);
	}
	return 0;
}
