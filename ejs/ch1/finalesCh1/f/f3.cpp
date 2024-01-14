#include <iostream>
using namespace std;

const int INF = 1e8;

int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int max_s = -INF, res = -INF;
        for(int i=0; i<n; i++){
            int s;
            scanf("%d", &s);
            // en cada iteracion, me interesa cual fue la nota maxima entre las notas de la izquierda (lo que ya recorri)...
            // siempre voy a estar actualizando max_s ... 
            res = max(res, max_s - s);
            max_s = max(max_s, s);
        }
        printf("%d\n", res);
    }

    return 0;
}