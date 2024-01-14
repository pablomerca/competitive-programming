#include <iostream>


using namespace std;

void f(int money){
    // podia usar else if y no hacer nesting.
    if(money < 2){
        printf("Copper\n");
        return;
    }
    if(money == 2){
        printf("Estate or Copper\n");
        return;
    }
    if(money>=3 && money<5){
        printf("Estate or Silver\n");
        return;
    }
    if(money == 5){
        printf("Duchy or Silver\n");
        return;
    }
    if(money>=6 && money<8){
        printf("Duchy or Gold\n");
        return;
    }
    if(money>=8){
        printf("Province or Gold\n");
        return;
    }
}

int main(){

    int g, s, c;
    scanf("%d %d %d", &g, &s, &c);
    f(g*3 + s*2 + c*1);
    return 0;
}