#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float m,n;
    int res;
    while(scanf("%f %f", &n, &m), (n || m)){
        if(n >= 3 && m >= 3) res = int(ceil((n*m)/2));
        else{
            if(n == 1 || m == 1) res = max(n, m);
            else{
                int nElems = n*m;
                // separate into groups of 8, in which 4 squares have horses...
                int rest = nElems%8; 
                switch(rest){
                    // rests can only be even numbers, because we have 2 rows.
                    case 0:
                        res = 4*(nElems/8);
                        break;
                    case 2:
                    case 4:
                        res = 4*(nElems/8) + rest;
                        break;
                    case 6:
                        res = 4*(nElems/8) + 4;
                        break;
                    default:
                        break;
                }
            }
        }
        printf("%d knights may be placed on a %.0f row %.0f column board.\n", res, n, m);
    }
    return 0;
}