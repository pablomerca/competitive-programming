#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        char piece;
        float n, m, res; // n and m > 4, so no corner cases :)
        scanf(" %c %f %f", &piece, &n, &m);  // space before c, bc char does not consume blank spaces atomatically.

        switch(piece){

            case 'r':
                res = min(n,m);
                break;
            case 'k':
                res = (n*m)/2;
                break;
            case 'Q':
                res =  min(n,m);
                break;
            case 'K':
                res = ceil(n/2) * ceil(m/2); // important
                break;
            default:
                res = -99;
                break;
        }
        printf("%d\n", int(res));
    }

    return 0;
}