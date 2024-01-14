#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    bool found = false;
    scanf("%d", &n);
    while (n-- && !found) { // si ya lo encontre, no hace falta recorrer mas restaurantes.
        int k;
        scanf("%d\n", &k);
        char restaurant[102];
        fgets(restaurant, 101, stdin);
        bool has_panc = false, has_soup = false;  // esto se resetea para cada restaurante.

        for (int i = 0; i < k; i++) {
            char plate[102];
            // Use getchar to consume the newline character
            scanf(" %100[^\n]", plate);
            // getchar(); // en la linea de arriba, al llegar al \n, no lo consumimos, de ahi el error.

            if (strcmp(plate, "pancakes") == 0) has_panc = true;
            else if (strcmp(plate, "pea soup") == 0) has_soup = true;
            
            if (has_panc && has_soup) {
                printf("%s", restaurant);
                found = true;
                break;
            }
        }
    }
    if (!found) printf("Anywhere is fine I guess\n");
    return 0;
}



// scanf(" %100[^\n]", plate);
// cada vez que queremos llenar un string de esa maner, tenemos que anteponer un espacio al %, ya que por
// alguna razon, hay un char fantasma \n que queda ensuciando el buffer, que solo se puede limpiar
// anteponiendo un espacio... si quisieramos consumirlo con getchar(), nos come un char posta, no el \n, una mierda...

// EL PROBLEMA REAL ES QUE CUANDO USAMOS scanf(" %100[^\n]", plate); cuando encuentra un char excluido, corta y no lo consumeeee!!!!
// entonces tenemos que consumirlo manualmente, ya sea en la siguiente iteracion agregando un espacio antes del %, o 
// en la misma iteracion, justo despues de consumir la linea hasta el \n.
// ^^^ LA RESPUESTA ESTA BIEN, PERO LO MAAAAS SEGURO ES SIEMPRE USAR EL ESPACIO ANTES DEL %.

// hay un par de edge cases en los que consumir el char luego del scanf no funca todavia xd.
// de todas formas, no hace ningun danio poner un espacio, ya que si no hay nada para skipear, simplemente lo ignora...