#include <iostream>
#include <linear
#include <cmath>
using namespace std;
using pos = pair<float, float>;

bool board[8][8];

pos checkDiagonal()


inline float dist(pos p1, pos p2){
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int getMinDir(float x1, float y1, float x2, float y2){
    float currMin = 10000.0;
    int res = -1;
    float arr[] = {hypot(), hypot(), hypot(), hypot()};

    for(int i=0; i<4; i++){
        if(arr[i] < currMin){
            currMin = arr[i];
            res = i;
        }
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char c1, c2;
        int r1, r2;
        scanf(" %c %d %c %d", &c1, &r1, &c2, &r2);
        float x1 = 8 - r1;
        float y1 = c1 - 'A';
        float x2 = 8 - r2;
        float y2 = c2 - 'A';

        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                board[i][j] = false;

        

        
        printf("p1: (%f, %f) - p2: (%f, %f)\n", x1, y1, x2, y2);
    }

    return 0;
}