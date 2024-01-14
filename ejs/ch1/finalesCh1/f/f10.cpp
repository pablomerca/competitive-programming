#include <iostream>
#include <vector>
using namespace std;

int r,c;
vector<vector<char>> mapa;
vector<vector<bool>> visited;

void nextPos(int& i, int& j){
    if(mapa[i][j] == 'N') i--;
    else if(mapa[i][j] == 'S') i++;
    else if(mapa[i][j] == 'W') j--;
    else j++; // else mapa[i][j] = 'E'
}


// Treasure Hunt - Kattis, solved by Pablo Mercado
int main(){

    scanf("%d %d\n", &r, &c);
    mapa = vector<vector<char>>(r, vector<char>(c, 'x'));
    visited = vector<vector<bool>>(r, vector<bool>(c, false));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            scanf("%c", &mapa[i][j]);  // mapa+i+j , esta bien si lo trato como array? NOP, mapa no es ptr.
        getchar(); // el %c no skipea \n, asi que tenemos que consumirlo aparte al final de cada row, podria haber usado fgets
    }

    // ahora si, recorremos el mapa
    int i=0, j=0, ct=0;
    while( (0<=i && i<r) && (0<=j && j<c) && !visited[i][j] &&  mapa[i][j]!='T'){
        ct++;
        visited[i][j] = true;
        nextPos(i,j);
    }
    if(!(0<=i && i<r) || !(0<=j && j<c)) printf("Out\n");   
    else if(visited[i][j]) printf("Lost\n");
    else printf("%d\n", ct);

    return 0;
}
