#include <iostream>
using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    char codeLine[42];

    for(int i=0; i<5; i++){
        if(i==3) scanf("%s", codeLine); // solo hace falta una linea (la 3ra, index 0) para reconocer cada numero.
        else scanf("%*s");  // esto es para ignorar una linea, la sintaxis es correcta.
    }

    int i=0;
    while(i<4*n){
        if(codeLine[i+1] == '*') printf("1");  // .*.
        else if(codeLine[i] == '*') printf("2"); // *..
        else printf("3"); // ..*
        i += 4;
    }
    printf("\n");

    return 0;
}