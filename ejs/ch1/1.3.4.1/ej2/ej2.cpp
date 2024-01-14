#include <iostream>
#include <cmath>
#include <numbers>


// using namespace std;

int main(){

    float pi = 3.14159265358979323846;
    
    int n;
    while(scanf("%d", &n) != EOF){

        printf("%.*f\n", n, pi);   

        // el * es para poner ese campo specifier con una variable
        // solo se puede usar una vez, por cada %, y la el valor de * se
        // debe poner justo antes de la variable que debe leer el %.
    }

    return 0;
}