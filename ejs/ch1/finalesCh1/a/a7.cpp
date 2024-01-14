#include <iostream>

using namespace std;

int main(){

    char name[51];
    // esta es la vesion corecta, name tiene que tener 1 espacio mas que la long max, para que entre el \0 char de end.
    // en el width contamos los chars que leemos, pero tenemos que tener espacio de width+1.
    scanf("%50[^\n]", name);
    printf("Thank you, %s, and farewell!\n", name);

    return 0;
}

// %50[^\n] , que lea todo menos el salto de linea, ya sabemos que el input tiene solo chars legales xd.
// usamos ese specifier ya que el %s corta al encontrar new line o blank space... xlt seria incapaz de 
// leer un nombe completo que tiene un espacio de por medio...
// El specifier de arriba nos dice que tenemos que leer chars hasta encontrarnos con el caracter de \n o hasta
// que se acabe el width... es importante poner que corte en las \n, de lo contario, nos llenaria el nombre con los 
// saltos de linea tambien xd.