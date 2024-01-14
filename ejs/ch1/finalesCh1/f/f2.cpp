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
    if(hash == 0) return -1;  // si no hay mas nombres que leer
    if(hash%9 == 0) return 9;
    else return hash%9;
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

// importante, para computar eficientemente la suma continua de los digitos de un numero hasta que me da 
// 1 solo digito, puedo usar el criterio de divisibilidad del 9. Un numero es divisible por 9, sii, la suma
// reductora de un numero da justo 9, sino no lo es... pero es resto mod 9 en ese caso, nos da el resultado
// de la suma reductora xd.

// esta operacion de duma reductora un realidad se llama digital root. Y esta relacionada con el mod 9.