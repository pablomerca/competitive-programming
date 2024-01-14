#include <iostream>
#include <cmath>

using namespace std;

// hasta la r-esima row completa entran sumGaus(r);
// entonces para saber cuantas rows llenamos con n soldados, tenemos que igualar sumGaus(r) = n
// luego despejo r y tomo parte entera para eliminar el resto.
// r^2 + r - 2n = 0   , a=1  b=1  c=-2n

int main(){

    int t;
    long long n;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        long double discriminante = sqrt(1 + 4*(2*n));
        long double x1 = (-1 + discriminante)/2;  // no necesitamos la segunda raiz ya que sera siempre negativa.
        printf("%lld\n", (long long)(x1));
    }
    return 0;
}


// muchiiiisimo ojo con la representacion de los numeros 2^32 < 10^9.6
// 2^64 < 10^19