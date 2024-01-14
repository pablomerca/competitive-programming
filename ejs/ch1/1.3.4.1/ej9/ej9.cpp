#include <stdio.h>
#include <stdlib.h>  // aca estan itoa y strtol, stoi no esta disponible en este compilador
using namespace std;

int main(){

    // tengo que tomar el valor de input en un string con la base de entrada con stoi, luego convertir el valor
    // de entrada a decimal y luego a la base de salida con itoa
    char num_input[33], num_output[33];  // como maximo podemos ingresar un numerto de 33 digitos
    int baseIn, baseOut;

    printf("Enter a number followed by a baseIn and baseOut: ");
    scanf("%s %d %d",&num_input, &baseIn, &baseOut);
    
    long int i_dec = strtol(num_input, NULL, baseIn); // el segundo param no lo usamos
    int numDec = int(i_dec);  // itoa toma int, por eso, tenemos que hacer la conversion

    itoa(numDec, num_output, baseOut);

    printf("%s (base %d) = %s (base %d)\n", num_input, baseIn, num_output, baseOut);
    return 0;
}

// strtol convierte un C-string que interpreta como un numero en la base de input, a un long int (decimal).
// itoa toma un int (decimal) y escribe en un C-string, ese numero, pero en la base que le pasamos

// (str))baseIN -> (int)decimal -> (str)baseOut


// en vez de usar strtoi, podemos usar stoi, pero este esta en el header string... ademas que usa el type string
// en vez de char* .