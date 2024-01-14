#include <iostream>
using namespace std;

int main(){

    double C, X, M;
    scanf("%lf %lf %lf", &C, &X, &M);
    double maxSpd = -1.0;

    for(int i=0; i<6; i++){

        double spd, efi;
        scanf("%lf %lf", &spd, &efi);
        double totalConsume = M/efi;
        double avlFuel = (C*0.5) - (M*X)/spd;
        if(avlFuel >= totalConsume && spd > maxSpd) maxSpd = spd;
    }
    if(maxSpd > -1.0) printf("YES %d\n", int(maxSpd));   
    else printf("NO\n");
    return 0;
}