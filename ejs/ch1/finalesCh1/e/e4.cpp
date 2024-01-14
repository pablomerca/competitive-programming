#include <iostream>

using namespace std;


int main(){

    int n, nCase = 0;
    while(scanf("%d", &n), n){
        int given = 0, owed = 0;
        while(n--){
            int event;
            scanf("%d", &event);
            if(event == 0) given++;
            else owed++;
        }
        printf("Case %d: %d\n", ++nCase, owed-given);
    }
    return 0;
}