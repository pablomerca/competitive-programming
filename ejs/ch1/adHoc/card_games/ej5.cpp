#include <iostream>
using namespace std;

int get_points(char val, char suite, char B){

    int res;
    switch (val){
        case 'A':
            res = 11;
            break;
        case 'K':
            res = 4;
            break;

        case 'Q':
            res = 3;
            break;

        case 'J':
            res = (suite == B ? 20 : 2);
            break;

        case 'T':
            res = 10;
            break;
        
        case '9':
            res = (suite == B ? 14 : 0);
            break;

        default:
            res = 0;
            break;
    }

    return res;
}


int main(){

    int N, points = 0; 
    char B, card[3];
    scanf("%d %c", &N, &B);

    for(int i=0; i<4*N; i++){
        scanf("%s", card);
        points += get_points(card[0], card[1], B);
    }
    printf("%d\n", points);
    return 0;
}