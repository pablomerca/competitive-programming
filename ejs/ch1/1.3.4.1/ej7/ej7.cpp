#include <iostream>
#include <list>
#include <vector>
using namespace std;

list<int> nums;  // los numero candidatos, son lista, ya que 
vector<int> S;
int n;

// en cada iteracion completamos el i-esimo elemento de las permutaciones
void generarPermutaciones(int i){
    if(i==n){  // printeamos el resultado, nums deberia llegar vacio
        for(int elem : S)
            printf("%d ", elem);
        printf("\n");
    }
    // nums.size() varia entre llamados, ya que popeamos antes de llamar recursivamente
    for(int j=0; j<nums.size(); j++){
        int elem = nums.front();
        S[i] = elem;
        nums.pop_front();  // para eliminar el elemento que ya puse 
        generarPermutaciones(i+1);
        nums.push_back(elem); // backtracking para que en el llamado de la prox iter, elem este disponible (atras)
    }
}

int main(){
    cin>> n;
    S.assign(n, -1);
    for(int i=0; i<n; i++){
        int elem;
        scanf("%d", &elem);
        nums.push_back(elem);
    }
    generarPermutaciones(0);
    return 0;
}