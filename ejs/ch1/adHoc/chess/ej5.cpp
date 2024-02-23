#include <iostream>
using namespace std;
using pos = pair<int, int>;

bool board[8][8];
int rowRes, colRes;

inline bool validPos(int x, int y){
    return (0<=x && x<8) && (0<=y && y<8);
}

void paintDirection(int x, int y, int dRow, int dCol){
    while(1){
        x += dRow;
        y += dCol;
        if(!validPos(x, y)) break;
        if(board[x][y]){
            rowRes = x;
            colRes = y;
            break;
        }  
        else board[x][y] = true;
    }
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char c1, c2;
        int r1, r2;
        scanf(" %c %d %c %d", &c1, &r1, &c2, &r2);
        int x1 = 8 - r1;
        int y1 = c1 - 'A';
        int x2 = 8 - r2;
        int y2 = c2 - 'A';

        rowRes = -1, colRes = -1;
        int dRow = x2 - x1;
        int dCol = y2 - y1;

        if((x1 + y1)%2 != (x2 + y2)%2) printf("Impossible\n");
        else if(x1 == x2 && y1 == y2) printf("0 %c %d\n", c1, r1);
        else if(abs(dRow) == abs(dCol)) printf("1 %c %d %c %d\n", c1, r1, c2, r2);
        else{
            // case same row
            if(dRow == 0){
                colRes = (y1 + y2)/2;
                if(x1 + abs(dCol/2) <= 8) rowRes = x1 + abs(dCol/2);
                else rowRes = x1 - abs(dCol/2);
            }
            // case same col
            else if(dCol == 0){ 
                rowRes = (x1 + x2)/2;
                if(y1 + abs(dRow/2) <= 8) colRes = y1 + abs(dRow/2);
                else colRes = y1 - abs(dCol/2);
            }
            // different row and col
            else{

                for(int i=0; i<8; i++)
                    for(int j=0; j<8; j++)
                        board[i][j] = false;

                // turn into unitary vectors
                paintDirection(x1, y1, -1, 1);
                paintDirection(x1, y1, 1, 1);
                paintDirection(x1, y1, 1, -1);
                paintDirection(x1, y1, -1, -1);

                paintDirection(x2, y2, -1, 1);
                paintDirection(x2, y2, 1, 1);
                paintDirection(x2, y2, 1, -1);
                paintDirection(x2, y2, -1, -1);
            }

            printf("2 %c %d %c %d %c %d\n", c1, r1, 'A'+ colRes, 8 - rowRes, c2, r2);
        }
    }
    return 0;
}