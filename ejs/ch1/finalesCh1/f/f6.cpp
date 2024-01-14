#include <iostream>
#include <math.h>
using namespace std;

void x(int& i, int num){
    if(num == 1){
        i++;
        return;
    }
    // para calcular #digitos(N) = floor(log(N)) + 1
    x(++i, int(log10(num)) + 1);
}


int main(){

    char ch, lastCh;
    while(scanf("%c", &ch), ch != 'E'){ // aca ya consumimos un char, asi que tam debe empezar en 1
        int tam = 1;
        lastCh = ch; // no hace falta actualizarlo dentro del prox while, ya que solo lo vemos cuando tam == 1.
        while(scanf("%c", &ch), ch != '\n'){
            tam++;
        } 
        // ahora tam tiene la longitud del numero inicial, osea ya tiene x_1.
        if(lastCh == '1' && tam == 1){  // edge case, si x0 = 1, lo procesamos por separado, xq la funcion la calcula mal.
            printf("1\n");
        } 
        else{
            int i=1;
            x(i, tam);
            printf("%d\n", i);
        }
    }
    return 0;
}
