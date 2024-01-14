#include <iostream>

using namespace std;

int main(){
    int T, n, nCase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int lowJumps = -1, highJumps = 0;
        int alturaPasada = 1e9;

        for(int i=0; i<n; i++){
            int alturaSiguiente;
            scanf("%d", &alturaSiguiente);
            if(alturaSiguiente > alturaPasada) highJumps++;
            if(alturaSiguiente < alturaPasada) lowJumps++;
            alturaPasada = alturaSiguiente;
        }
        printf("Case %d: %d %d\n", ++nCase, highJumps, lowJumps);
    }

    return 0;
}