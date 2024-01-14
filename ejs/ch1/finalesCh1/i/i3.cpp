#include <iostream>
using namespace std;

int main(){

    int H, W;
    while(scanf("%d %d", &H, &W), (H || W)){
        int lastLevel = H, ct = 0, lvl; // lastLvl empieza en H, ya que asi sumamos de entrada la diferencia H - lvl.
        for(int j=0; j<W; j++){
            scanf("%d", &lvl);
            ct += max(0, lastLevel - lvl);  // sumamos la diferencia de niveles solo cuando: lvl < lastLevel -> lasLvl - lvl > 0
            lastLevel = lvl;
        }
        printf("%d\n", ct);
    }
    return 0;
}