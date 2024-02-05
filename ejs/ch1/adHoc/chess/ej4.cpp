#include <iostream>
#include <string>
using namespace std;

// #: ocupied position, *: empty attacked position, ' ': empty un-attacked postion

char board[8][8];
int attackedPositions, initialPieces;

int board_init(char* fen){
    int j = 0, initialPieces = 0;
    for(int s=0, i=0; fen[s]; s++){
        char ch = fen[s];
        if(j>=8) j=0, i++;
        if(ch == '/') continue;
        if(isdigit(ch)){
            int temp = (ch - '0');
            while(temp--) board[i][j++] = ' ';
            continue;
        } 
        board[i][j] = '#';
        initialPieces++;
        j++;
    }
    return initialPieces;
}

inline bool valid_pos(int row, int col){
    return (0<=row && row<8) && (0<=col && col<8);
}

void walk_to(int row, int col){
    if(valid_pos(row, col) && board[row][col] == ' '){
        attackedPositions++;
        board[row][col] = true;
    }
}

void checkDirection(int row, int col, int dRow, int dCol){
    while(1){
        row += dRow;
        col += dCol;
        if(!valid_pos(row, col) || board[row][col] == '#') break;
        if(board[row][col] == ' '){
            attackedPositions++;
            board[row][col] = '*';
        }
    }
}

void rook(int row, int col){
    // chech upper vertical, move towards upper rows (lower indexes).
    checkDirection(row, col, -1, 0);
    // chech lower vertical, move towards upper rows (higher indexes).
    checkDirection(row, col, 1, 0);
    // chech right horizontal, move towards higher cols (higher indexes).
    checkDirection(row, col, 0, 1);
    // chech left horizontal, move towards lower cols (lower indexes).
    checkDirection(row, col, 0, -1);
}

void bishop(int row, int col){
    // upper left diag, row-- col--
    checkDirection(row, col, -1, -1);
    // upper right diag, row-- col++
    checkDirection(row, col, -1, 1);
    // lower left diag, row++ col--
    checkDirection(row, col, 1, -1);
    // lower right diag, row++ col++
    checkDirection(row, col, 1, 1);
}

void queen(int row, int col){
    rook(row, col);
    bishop(row, col);
}

void king(int row, int col){
    for(int i=0; i<3; i++){
        walk_to(row-1, col-1+i);
        walk_to(row+1, col-1+i);
    }
    walk_to(row, col-1);
    walk_to(row, col+1);
}

void pawn(int row, int col, char ch){
    if(ch == 'P'){ // white below, attacks upper corners
        walk_to(row-1, col-1);
        walk_to(row-1, col+1);
    }
    else{ // black top, attacks lower corners
        walk_to(row+1, col-1);
        walk_to(row+1, col+1);
    }
}

void knight(int row, int col){
    // lower
    walk_to(row+2, col-1);
    walk_to(row+2, col+1);
    // upper 
    walk_to(row-2, col-1);
    walk_to(row-2, col+1);
    // left
    walk_to(row-1, col-2);
    walk_to(row+1, col-2);
    // right
    walk_to(row-1, col+2);
    walk_to(row+1, col+2);
}


int main(){

    char fen[68]; 
    while(scanf("%s", &fen) != EOF){

        attackedPositions = 0;
        int initialPieces = board_init(fen);

        // now, process the range of each piece in the board.
        int j = 0;
        for(int s=0, i=0; fen[s]; s++){

            char ch = fen[s];

            if(j>=8) j=0, i++;
            if(ch == '/') continue;
            if(isdigit(ch)){
                j += (ch - '0'); // ya que en la guarda hace j++
                continue;
            } 
            // a partir de aca, ya sabemos que nos topamos con una pieza en la notacion fen.

            // to lower does not modify the char...
            switch (tolower(ch)){
                case 'r':
                    rook(i,j);
                    break;
                case 'b':
                    bishop(i,j);
                    break;
                case 'q':
                    queen(i,j);
                    break;
                case 'p':
                    pawn(i,j,ch);
                    break;
                case 'n':
                    knight(i,j);
                    break;
                case 'k':
                    king(i,j);
                    break;
                default:
                    break;
            }
            j++;
        }
        int ans = 64 - (attackedPositions + initialPieces);
        printf("%d\n", ans);
    }
    return 0;
}