#include <iostream>

using namespace std;

int main(){

    int t; scanf("%d", &t);
    while(t--){
        float n; scanf("%f", &n);
        float res = n*567;
        res = 7492 + res/9;
        res *= 235;
        res = (res/47) - 498; 
        int ans = int(res/10);
        printf("%d\n", abs(ans%10)); // el abs es por si da negativo el mod, ya que n puede ser negativo.
    }
    return 0;
}