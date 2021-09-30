// Ejercicio 4: Dado un arreglo de enteros nums, devuelve todos los tripletes [nums [i], nums [j], nums [k]]
// tales que i! = J, i! = K, y j! = K y nums [i] + nums [j] + nums [k] == 0.
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  set<vector<int>> s; // para obtener tripletes unicos
  sort(nums.begin() , nums.end());
  int n = nums.size();
  vector<int> temp;
  temp.resize(3);
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
      if(binary_search(nums.begin() + j + 1, nums.end(), -nums[i] - nums[j])){
        temp[0] = nums[i], temp[1] = nums[j], temp[2] = -nums[i]-nums[j];
        sort(temp.begin(),temp.end());
        //to get triplet in an order, will be easy to check if
        //duplicate exists or not
        s.insert(temp);
      }
    }
    vector<vector<int>> ans;
    for(auto triplet: s)
      ans.push_back(triplet);
    return ans;
}

void display_ans(vector<vector<int>> temp){
  for(auto triplet : temp)
    cout << triplet[0] << " " << triplet[1] << " " << triplet[2] <<"\n";
}

//main
int main(){

	// Caso de prueba:
	// Entrada : {-1,0,1,2,-1,-4}
	// Salida: {1-, -2, 2} {-1 0 1}
	
    vector<int> v{-1,0,1,2,-1,-4};
    display_ans(threeSum(v));

    return 0;
}
