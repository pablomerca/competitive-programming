#include <iostream>
using namespace std;


int main(){

    int w,l, nCase = 0;  // w es la dimension del eje x, l la del eje y.
    while(scanf("%d %d", &w, &l), (w || l)){
        int n, xReal=0, yReal=0, xRobot=0, yRobot=0;
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            char dir;
            int dist;
            scanf(" %c %d", &dir, &dist); // importante poner espacio antes de % ya que el char no consume de por si el \n.

            if(dir == 'u'){
                yRobot += dist;
                yReal = min(l-1, yReal + dist);
            }
            else if(dir == 'd'){
                yRobot -= dist;
                yReal = max(0, yReal - dist);
            }
            else if(dir == 'r'){
                xRobot += dist;
                xReal = min(w-1, xReal + dist);
            }
            else{ // dir == l
                xRobot -= dist;
                xReal = max(0, xReal - dist);
            }
        }
        if(nCase > 0) printf("\n\n");  // para que no imprima al final 2 saltos de linea.
        printf("Robot thinks %d %d\nActually at %d %d", xRobot, yRobot, xReal, yReal);
        nCase++;
    }

    return 0;
}

// importante, cuando leemos numeros que terminan con un \n ese char no se consume automaticamente,
// sino que queda en el buffer de entrada... si a continuacion leemos un char, se va a comer el \n.
// Para evitar esto, tenemos que agregar un espacio asi: " %c", asi comemos cualquier cantidad de
// espacio en blanco que haya quedado sin consumir de antes.