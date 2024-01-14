#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T, nCase = 0;
    scanf("%d", &T);
    int puntaje[10];
    char url[10][103];  // array de string, o matriz de char.

    while(T--){
        for(int i=0; i<10; i++)
            scanf("%s %d", url[i], &puntaje[i]);
        
        int puntajeMax = -1;
        for(int i=0; i<10; i++)
            puntajeMax = max(puntajeMax, puntaje[i]);
        
        printf("Case #%d:\n", ++nCase);
        for(int i=0; i<10; i++){
            if(puntaje[i] == puntajeMax) printf("%s\n", url[i]);
        }
    }
    return 0;
}