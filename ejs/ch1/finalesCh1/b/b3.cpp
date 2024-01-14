#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        float n,m;
        scanf("%f %f", &n, &m);
        int res = int( ceil((n-2)/3) * ceil((m-2)/3) );
        printf("%d\n", res);
    }


    return 0;
}