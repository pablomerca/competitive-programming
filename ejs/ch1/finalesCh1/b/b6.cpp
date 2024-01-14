#include <iostream>

using namespace std;


int main(){

    int n; 
    float res = 0;
    scanf("%d", &n);

    while(n--){
        float q,y; 
        scanf("%f %f", &q, &y);
        if(q!=0 && y!=0) res += q*y;
    }
    printf("%.3f", res);
    return 0;
}