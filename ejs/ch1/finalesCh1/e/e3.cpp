#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int T, nCase = 0;
    scanf("%d", &T);
    while(T--){
        int n, speed, maxSpeed = -1;
        scanf("%d", &n);
        while(n--){
            scanf("%d", &speed);
            maxSpeed = max(speed, maxSpeed);
        }
        printf("Case %d: %d\n", ++nCase, maxSpeed);
    }
    return 0;
}