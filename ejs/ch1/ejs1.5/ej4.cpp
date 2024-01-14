#include <iostream>
#include <cstring>
#include <vector>
#include <string>   
#include <algorithm>
using namespace std;


int main(){

    char T[] = "i love cs3233 competitive programming. i also love algorithm";
    vector<string> V;
    char* pch = strtok(T, " .");

    while(pch != nullptr){
        V.push_back(string(pch));
        pch = strtok(nullptr, " .");   // al pasar puntero null, comienza a buscar en el punto donde cerro el ultimo token.
    }

    printf("valores del vector antes de ordenar:\n");
    for(string& str : V) cout<< str <<"\n";
    printf("\n");

    sort(V.begin(), V.end());  // las strings se ordenan por default de forma lexicografica.
    
    printf("valores del vector despues de ordenar:\n");
    for(string& str : V) cout<< str <<"\n";

    return 0;
}