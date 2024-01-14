#include <iostream>
using namespace std;

int main(){

    int hotelPrice[18];
    int N,B,H,W;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){

        int precioMinimo = 1e9;

        for(int i=0; i<H; i++){
            bool cumplePrecio = false, cumpleCupo = false;
            scanf("%d", &hotelPrice[i]);
            if(hotelPrice[i]*N <= B) cumplePrecio = true;

            for(int j=0; j<W; j++){
                int bedsPerWeek;
                scanf("%d", &bedsPerWeek);
                if(bedsPerWeek >= N) cumpleCupo = true;
            }

            if(cumplePrecio && cumpleCupo && hotelPrice[i]*N < precioMinimo){
                precioMinimo = hotelPrice[i]*N;
            }
        }
        if(precioMinimo < 1e9) printf("%d\n", precioMinimo);
        else printf("stay home\n");
    }

    return 0;
}