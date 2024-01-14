#include <iostream>
#include <list>
#include <vector>
using namespace std;

list<int> S;  //es list ya que tenemos que agregar elementos dinamicamente, cambia su size en cada sub-set
vector<int> nums; // necesitamos los index, no cambia entre llamados, solo recorremos en rangos
int n;

void generarSubSets(int i){
    if(i==n) return;
    while(i<n){
        S.push_back(nums[i]);
        // imprimimos el subSet que se nos forma
        printf("{ ");
        for(int elem : S)
            printf("%d ", elem);
        printf("}\n");
        // llamamos a los siguientes con S con el valor insertado
        generarSubSets(i+1);
        // backtrack
        S.pop_back();
        i++;
    }
}

int main(){
    cin>> n;
    nums.resize(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    // primero imprimimos el conjunto vacio:
    printf("{ }\n");
    generarSubSets(0);

    return 0;
}