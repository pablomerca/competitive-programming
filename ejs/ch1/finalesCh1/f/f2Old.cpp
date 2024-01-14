#include <iostream>
#include <cmath>
using namespace std;

int getHash(){

    char ch;
    int hash = 0;
    while(scanf("%c", &ch) != EOF && ch != '\n'){
        if(!('a'<= ch && ch <= 'z') && !('A'<= ch && ch <= 'Z')) continue; // si no es una letra, la ignoro, leo la siguiente
        if('A'<= ch && ch <= 'Z') ch += ('a' - 'A'); // si es upper-case, pasamos a lower case, 'a' - 'A' = 32
        hash += (ch - 'a') + 1; // el valor de un digito
    }
    // si ya no hay mas nombres para leer
    if(hash == 0) return -1; 

    while(hash >= 10){ // mientra tenga mas de 1 digito
        // sumamos todos los digitos
        int acu = 0;   // puedo usar a hash directamente como temp
        while(hash){
            acu += hash%10;
            hash /= 10;
        }
        hash = acu;
    }
    return hash;
}


int main(){

    while(1){
        float name1 = float(getHash());
        if(name1 == -1) break;  // si no habia un nombre para leer, termiamos los tests
        float name2 = float(getHash());

        float res = min(name1, name2)/max(name1, name2); 
        printf("%.2f %\n", res*100); 
    }
    return 0;
}