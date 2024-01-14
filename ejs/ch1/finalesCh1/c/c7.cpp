#include <iostream>
using namespace std;

int main(){

    float a, b;   // f(x) = a.x + b
    scanf("%f %f", &b, &a);

    if(b == 0){  // ambas rectas se cortan en 0
        if(a == 1) printf("ALL GOOD\n"); // funcion y = x
        else printf("0\n");
    }
    else{ // b != 0
        if(a == 1) printf("IMPOSSIBLE\n"); // la funcion y su inversa son paralelas, ya que la pendiente es 1
        else{
            float res = (b*(1 + a)) / (1 - (a*a)); // x = y <==> f(x) = f^-1(y) = res
            printf("%.9f\n", res);
        }
    }

    return 0;
}