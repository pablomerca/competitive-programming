#include <iostream>
#include <cstring>
#include <string>   
#include <unordered_map>
using namespace std;


int main(){

    char T[] = "i love cs3233 competitive programming. i also love algorithm love";
    unordered_map<string, int> M;
    char* tok = strtok(T, " .");  // muy clave usar strtok para separar un string en sus palabras...
    int maxCount = 0;
    string res;
    while(tok != nullptr){
        string str(tok);
        if(M.count(str)) M[str]++;
        else M[str] = 1;
        if(M[str] > maxCount ){
            maxCount = M[str];
            res = str;
        } 
        tok = strtok(nullptr, " .");
    }

    printf("la palabra mas frecuente es: ");
    cout<< res << "\n";
    return 0;
}