#include <iostream>

using namespace std;

int main(){

    char str[15];
    // char str[3] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    while(fgets(str, 15, stdin))  // fgets retorna nullprt, osea 0, si no puede leer el input, esto va a pasar en EOF
        printf("%s", str);  // aca el salto de linea ya se lo come el string, osea que ya lo incluye en sus chars...

    return 0;
}

// siempre tenemos que reservar memoria para n+1 chars cuando usamos fgets, para guardad el char de fin.
// en este caso, vamos a poder ller 14 chars, en 15-avo es para la terminacion  