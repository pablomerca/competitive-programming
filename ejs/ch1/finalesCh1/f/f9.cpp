#include <iostream>
using namespace std;

// estas 2 funciones se podrias juntar en una sola que tenga un bool como 3er param, que
// nos indique si la rotacion es horaria o no... cada vez que veo (s-t) o (t-s), lo puedo
// reemplazar por abs(s-t), ya que la separacion de casos se encarga que el resultado sea correcto...

int rotClockWise(int s, int t){
    if(s<t) return (t-s)*9;
    else return (40 - (s-t))*9;
}

int rotCounterClockWise(int s, int t){
   if(s<t) return (40 - (t-s))*9;
    else return (s-t)*9;
}

int main(){

    int s,n1,n2,n3;
    while(scanf("%d %d %d %d", &s, &n1, &n2, &n3), (s || n1 || n2 || n3)){
        // en total damos 3 vueltas completas, da igual si las sumo al comienzo 
        int res = 3*360 + rotCounterClockWise(s, n1) + rotClockWise(n1, n2) + rotCounterClockWise(n2, n3);
        printf("%d\n", res);
    }
    return 0;
}