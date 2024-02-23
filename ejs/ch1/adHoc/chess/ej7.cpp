#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int getPrioriy(char piece){
    switch (tolower(piece)){
    case 'k':
        return 1;
    case 'q':
        return 2;
    case 'r':
        return 3;
    case 'b':
        return 4;
    case 'n':
        return 5;
    default:
        return 99;
    }
}

struct pos{
    pos(int i, int j, char piece) : piece(piece), colLetter('a' + j), rowNum(8 - i), isPawn(tolower(piece) == 'p'){}
    int rowNum;
    char colLetter;
    char piece;  // case sensitive
    bool isPawn;

    bool operator<(pos& p2){
        int priority_p1 = getPrioriy(piece);
        int priority_p2 = getPrioriy(p2.piece);

        if(priority_p1 == priority_p2){
            if(rowNum == p2.rowNum){
                return colLetter < p2.colLetter;
            }
            else{
                if(isupper(piece)) return rowNum < p2.rowNum;
                else return p2.rowNum < rowNum;
            }
        }
        else return priority_p1 < priority_p2;
    }

};

void printPositions(vector<pos>& vp){
    for(int i=0; i<vp.size(); i++){
        if(vp[i].isPawn) printf("%c%d", vp[i].colLetter, vp[i].rowNum);
        else printf("%c%c%d", toupper(vp[i].piece), vp[i].colLetter, vp[i].rowNum);
        if(i < vp.size() - 1) printf(",");
    }
    printf("\n");
}

int main(){

    char boardRow[35];
    vector<pos> white, black;
    
    for(int row=0; row<8; row++){
        scanf("%*s %s", boardRow);

        for(int j=2; j<33; j+=4){
            char piece = boardRow[j];
            if(piece == '.' || piece == ':') continue;
            int col = (j-2)/4;
            pos p(row, col, piece);

            if(isupper(piece)) white.push_back(p);
            else black.push_back(p);
        }
    }
    scanf("%*s");

    sort(white.begin(), white.end());
    sort(black.begin(), black.end());

    printf("White: ");
    printPositions(white);
    printf("Black: ");
    printPositions(black);

    return 0;
}


// In case two pieces of the same type appear in the input, the piece
// with the smaller row number must be described before the other one if the pieces
// are white, 

// and the one with the larger row number must be described first if the pieces are
// black. 

// If two pieces of the same type appear 
// in the same row, the one with the smaller column letter must appear first.

// las rows son numeros, las cols son letras...