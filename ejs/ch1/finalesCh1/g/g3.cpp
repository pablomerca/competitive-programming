#include <iostream>
using namespace std;


int main(){
    int deuda[20], porCobrar[20], reserva[20]; // indexamos en 0 los bancos ojoo
    int B, N;
    while(scanf("%d %d", &B, &N), (B || N)){
        for(int i=0; i<B; i++){
            scanf("%d", &reserva[i]);
            deuda[i] = 0; porCobrar[i] = 0; // de paso inicializamos esto xd
        }
        for(int i=0; i<N; i++){
            int D, C, cash;
            scanf("%d %d %d", &D, &C, &cash);
            // restamos 1 a D y C para que indexe todo en 0
            porCobrar[C-1] += cash; 
            deuda[D-1] += cash;
        }

        bool posible = true;
        for(int i=0; i<B; i++)
            posible &= (reserva[i] + porCobrar[i] >= deuda[i]); // si esto se cumple para todos, entonces True.
        
        if(posible) printf("S\n");
        else printf("N\n");
    }
    return 0;
}
// podria optimizarlo usando solo un array reserva[], en cada iteracion, le sumo el dinero a reserva[C-1]
// y se lo resto a reserva[D-1], luego, la res es true sii, reserva[i] >= 0 para todos los bancos.