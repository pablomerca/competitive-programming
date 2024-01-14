#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int T;
    char inst[100];
    scanf("%d", &T);

    while(T--){
        int n, pos = 0;
        scanf("%d", &n);

        char word[7];
        for(int i=0; i<n; i++){

            scanf("%s", word);
            if(word[0] == 'L') inst[i] = -1;
            else if(word[0] == 'R') inst[i] = 1;
            else{ // SAME AS instrNumber
                int instrNumber;
                scanf("%*s %d", &instrNumber); // consumo "AS" y guardo el numero
                inst[i] = inst[instrNumber - 1];
            }
            pos += inst[i];
        }
        printf("%d\n", pos);
    }
    return 0;
}