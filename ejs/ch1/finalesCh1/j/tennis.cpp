#include <iostream>
using namespace std;

int findMatch(int p1, int p2){
    if(abs(p1 - p2) == 1 && max(p1, p2)%2 == 0) return 1;  // el min es impar y el max es par
    // por la division entera, si p1 era par, se va a truncar al numero correcto, si era impar, me va dar exacto el correcto 
    int nextSeed1 = (p1+1)/2; 
    int nextSeed2 = (p2+1)/2; 
    return 1 + findMatch(nextSeed1, nextSeed2);
}

int main(){
    int N, p1, p2;
    while(scanf("%d %d %d", &N, &p1, &p2) != EOF){
        int res = findMatch(p1, p2);
        printf("%d\n", res);
    }
    return 0;
}

// sabemos que en la primera ronda se realizan 2^(N-1) partidos, tenemos que ver en que partido k, participa cada
// jugador, supongamos que p1 juega en k1 y p2 juega en k2, luego
// en la ronda r, supongamos que hay 2^z jugadores, en la ronda r+1 va a haber 2^(z-1) jugadores.
// si en la ronda r, un juegador j se enfrentaba a uno j', entonces el seed del ganador de j vs j' en la ronda r+1
// sera max(j1, j2)/2 

// el caso base es cuando la seed de los jugadores dista en 1 unidad, entonces estan en el mismo match.
// dada una seed, S: 
//      si S es impar entonces S = 2k-1 <--> k = (S+1)/2
//      si S es  par entonces S = 2k <--> k = S/2

    // int k_p1 = (p1%2==0 ? p1/2 : (p1+1)/2); 
    // int k_p2 = (p2%2==0 ? p2/2 : (p2+1)/2); 



