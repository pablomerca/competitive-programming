#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

inline pair<int, int> getPos(int P){
    return make_pair(P/8, P%8);
}

// las 2 input values should be copies, bc they can be modified inside the function.
bool legal(pair<int, int>& kingPos, pair<int, int> currPos, pair<int, int> nextPos){

    bool noMovement = (currPos.first == nextPos.first && currPos.second == nextPos.second);
    bool legalCrossMove = (currPos.first == nextPos.first || currPos.second == nextPos.second);
    bool horizontalLegal = true, verticalLegal = true;
    // same row as king move check
    if(currPos.first == nextPos.first && kingPos.first == nextPos.first){
        if(currPos.second > nextPos.second) swap(nextPos.second, currPos.second);
        horizontalLegal = !(currPos.second <= kingPos.second && kingPos.second <= nextPos.second);  
    }
    // same col as king move check
    if(currPos.second == nextPos.second && kingPos.second == nextPos.second){
        if(currPos.first > nextPos.first) swap(nextPos.first, currPos.first);
        horizontalLegal = !(currPos.first <= kingPos.first && kingPos.first <= nextPos.first);  
    }
    return !noMovement && legalCrossMove && horizontalLegal && verticalLegal;
}

bool allowed(pair<int, int>& kingPos, pair<int, int>& queenPos){
    if(kingPos.first == queenPos.first && (abs(kingPos.second - queenPos.second) == 1)) return false;
    if(kingPos.second == queenPos.second && (abs(kingPos.first - queenPos.first) == 1)) return false;
    return true;
}

bool locked(int K, int Q){
    bool topLeft = (K == 0 && Q == 9);
    bool topRight = (K == 7 && Q == 14);
    bool bottomLeft = (K == 56 && Q == 49);
    bool bottomRight = (K == 63 && Q == 54);
    return (topLeft || topRight || bottomLeft || bottomRight);
}


int main(){
    int K, Q, nextQ;
    while(scanf("%d %d %d", &K, &Q, &nextQ) != EOF){
        pair<int, int> currPos = getPos(Q);
        pair<int, int> nextPos = getPos(nextQ);
        pair<int, int> kingPos = getPos(K);

        if(K == Q) printf("Illegal state\n");
        else if(legal(kingPos, currPos, nextPos)){
            if(allowed(kingPos, nextPos)){
                if(locked(K, nextQ)) printf("Stop\n");
                else printf("Continue\n");
            }
            else printf("Move not allowed\n");
        }
        else printf("Illegal move\n");
    }
    return 0;
}