#include <iostream>
#include <math.h>

using namespace std;

int p, a, b, c, d;
const int INF = 1e8;

inline float price(int k){
    return (p*((sin(a*k + b)) + (cos(c*k + d)) + 2));
}

int main(){
    int n;
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    float max_price = -INF, res = 0;

    for(int i=1; i<=n; i++){
        // la idea es la misma que el ejercicio f3
        float precioAct = price(i);
        res = max(res, max_price - precioAct);
        max_price = max(max_price, precioAct);
    }
    printf("%.6f", res);
}