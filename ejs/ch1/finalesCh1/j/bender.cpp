#include <iostream>
using namespace std;

int main(){

    int L;
    char dir[4];
    while(scanf("%d", &L), L){
        char curDir[] = "+x";

        for(int i=1; i<L; i++){
            scanf("%s", dir);
            if(dir[0] == 'N') continue;

            if(curDir[1] == 'x'){
                curDir[1] = dir[1]; // el eje va a ser el mismo que dir.
                // la direccion hay que ajustarla segun la direccion de curDir.
                if(curDir[0] == '-') curDir[0] = (dir[0]=='+' ? '-' : '+'); // invierto el signo de dir, si currDir == -x
                else curDir[0] = dir[0];   // le pongo el mismo signo que dir.
            }
            else if(curDir[1] == 'y'){
                if(dir[1] == 'z') continue;
                // if dir[1] == y ...
                curDir[1] = 'x';
                if(curDir[0]=='+') curDir[0] = (dir[0]=='+'? '-' : '+');
                else curDir[0] = dir[0];
            }
            else if(curDir[1] == 'z'){
                if(dir[1] == 'y') continue; 
                // if dir[1] = z ...
                curDir[1] = 'x';  
                if(curDir[0]=='+') curDir[0] = (dir[0]=='+'? '-' : '+');  // vamos al signo opuesto de dir
                else curDir[0] = dir[0];
            }
        }
        printf("%s\n", curDir);
    }

    return 0;
}

// DIRECTIONS LOGIC:
// si cur dir == -x, entonces tras un movimiento m, va a apuntar al opuesto de m, (osea, solo signo opuesto de m):
// si cur dir == x, entonces tras un mov m, va a apuntar el extr a la mims dir de m.

// si curr dir == +-y entonces cualquier movimiento en z no le afecta.
// si curr dir == +y entonces cualquier mov m en y, nos lleva a x con el signo contrario de m.
// si curr dir == -y entonces cualquier mov m en y, nos lleva a x con el mimsmo signo de m.

// si curr dir == +-z entonces cualquier movimiento en y no le afecta.
// si curr dir == +z entonces cualquier mov m en z, nos lleva a x con el signo contrario de m.
// si curr dir == -z entonces cualquier mov m en z, nos lleva a x con el mimsmo signo de m.