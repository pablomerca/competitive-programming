#include <iostream>
#include <cstring>
using namespace std;

inline int cardValue(char* card){
    return (isdigit(card[0]) ? card[0] - '0' : 10);
}

int main(){
    int T, nCase = 0; 
    scanf("%d", &T);

    while(T--){
        char deck[52][3];  // char**
        for(int i=0; i<52; i++) scanf("%s", deck[i]);

        int pos = 26, Y = -1;  // indexacion en 0, por eso Y = -1
        for(int i=0; i<3; i++){
            int X = cardValue(deck[pos]);
            Y += X;
            pos = pos - (10 - X) - 1;  // pos += X - 11;
        }

        int deleted_cards = 26 - pos;
        int ans_idx = (Y > pos ? Y+deleted_cards : Y);
        printf("Case %d: %s\n", ++nCase, deck[ans_idx]);  
    }

    return 0;
}