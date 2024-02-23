#include <iostream>
#include <string.h>
using namespace std;

char board[8][8];

void drawBoard(){

    char separator[] = "+---+---+---+---+---+---+---+---+";  // 33 char width
    char board_row_0[] = "|...|:::|...|:::|...|:::|...|:::|";
    char board_row_1[] = "|:::|...|:::|...|:::|...|:::|...|";

    printf("%s\n", separator);
    for(int row=0; row<8; row++){
        char* rowTemplate = (row%2 == 0 ? board_row_0 : board_row_1);
        for(int j=2; j<33; j+=4){
            int col = (j-2)/4;
            if(board[row][col] == 'x') rowTemplate[j] = rowTemplate[j+1];  // bc the j-th char may be a piece from a previous iteration.
            else rowTemplate[j] =  board[row][col];
        }
        printf("%s\n", rowTemplate);
        printf("%s\n", separator);
    }
}

void fillBoard(bool is_white, char* positions){

    char* pos = strtok(positions, " "); // to skip the first word.
    pos = strtok(nullptr, ",");

    while(pos){

        if(strlen(pos) == 3){  // bc pawn positions are only lenght 2
            char piece = pos[0];
            int row = 8 - (pos[2] - '0');  // translation of index base, from chess board to matrix.
            int col = pos[1] - 'a';
            board[row][col] = (is_white ? piece : tolower(piece));
        }
        else{
            int row = 8 - (pos[1] - '0');  // translation of index base, from chess board to matrix.
            int col = pos[0] - 'a';
            board[row][col] = (is_white ? 'P' : 'p');
        }
        pos = strtok(nullptr, ",");
    }

}

int main(){

    char white[155], black[155];
    scanf("%[^\n]", white);
    scanf(" %[^\n]", black);

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            board[i][j] = 'x';

    fillBoard(true, white);
    fillBoard(false, black);
    drawBoard();
    return 0;
}