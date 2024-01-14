#include <iostream>
using namespace std;

int main(){
    int T, nCase = 0;
    scanf("%d", &T);
    while(T--){

        int N, saldoMile = 0, saldoJuice = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            int mins;
            scanf("%d", &mins);
            // primero tomamos como valor incial, la divistion entera de los miniutos con el costo de tarifa.
            // luego tomatmos modulo... si es mayor a 0, entonces sumamos 1 mas al resultado anterior.
                
            saldoMile += (mins/30)*10;
            saldoMile += 10;  // creo q vasta con hacer saldoMile += 10

            saldoJuice += (mins/60)*15;
            saldoJuice += 15;
        }
        printf("Case %d: ", ++nCase);
        if(saldoMile < saldoJuice) printf("Mile %d\n", saldoMile);
        else if(saldoMile > saldoJuice) printf("Juice %d\n", saldoJuice);
        else printf("Mile Juice %d\n", saldoMile);
    }
    return 0;
}