#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;

const int MAX = 20;

char getRndChar(){
    return 'A' + rand()%8;
}
int getRndNum(){
    return rand()%8 + 1;
}

int main(){
    srand(time(0));
    int T = 10;
    printf("%d\n", T);
    for(int i=0; i<T; i++){
        printf("%c %d %c %d\n", getRndChar(), getRndNum(), getRndChar(), getRndNum());
    }

    return 0;
}