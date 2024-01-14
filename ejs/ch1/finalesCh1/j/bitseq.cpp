#include <iostream>

using namespace std;

// A = 1 -> 0
// B = 0 -> 1
// C = ? -> 1
// D = ? -> 0

int main(){

    char from[103], to[103];
    int T, nCase = 0; 
    scanf("%d", &T);
    while(T--){
        scanf("%s", from);
        scanf("%s", to);
        int A=0, B=0, C=0, D=0, res=0;
        for(int i=0; i<=101; i++){
            if(from[i] == '\0') break;
            if(from[i] == to[i]) continue;
            else if(from[i] == '1') A++; // 1 -> 0
            else if(from[i] == '0') B++; // 0 -> 1
            else{ // ? -> ...
                if(to[i] == '1') C++; // ? -> 1
                else D++;  // ? -> 0
            }
        }

        int temp = min(A,B);
        res += temp;
        B -= temp;
        A -= temp;
        if(A > C) printf("Case %d: -1\n", ++nCase);
        else{ // A < C
            res += A;
            C -= A;
            D += A;
            res += D + B + C;  // en este caso: A = 0, no lo sumo, asi que no lo actualizo arriba
            printf("Case %d: %d\n", ++nCase, res);
            // printf("Case %d: %d\n", ++nCase, res + A + B + C + D);  // se puede simplificar todo lo de arriba a esto xd.
        }
    }
    
    return 0;
}
