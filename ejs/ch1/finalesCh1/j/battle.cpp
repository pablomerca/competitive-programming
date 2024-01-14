#include <iostream>
#include <deque>
using namespace std;

inline void printCounterAttack(char& ch){
    switch(ch) {
        case 'R':
            printf("S");
            break;
        case 'B':
            printf("K");
            break;
        case 'L':
            printf("H");
            break;
    }
}

inline void process2(deque<char>& Q, int& cc){
    if(cc==148 || cc==158 || cc==142) return;
    char temp = Q.front();
    cc -= int(temp);
    Q.pop_front();
    printCounterAttack(temp);
}


int main(){

    char ch; 
    int cc = 0; 
    deque<char> Q;
    while(scanf("%c", &ch)!=EOF && ch != '\n'){

        Q.push_back(ch);
        cc += int(ch);
        if(Q.size() == 1) continue;
        if(Q.size() == 2) process2(Q, cc);
        if(Q.size() == 3){
            if(cc == 224){
                printf("C");
                Q.clear();
                cc = 0;
            }
            else{
                printCounterAttack(Q.front());
                cc -= int(Q.front());
                Q.pop_front();
                process2(Q, cc);
            }
        }
    }

    for(char& temp : Q) printCounterAttack(temp);
    printf("\n");
    return 0;
}

// R -> S
// B -> K
// L -> H

// RBL, RLB, BLR, BRL, LRB, LBR todas cuentan para el combo!!
