#include <iostream>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int dif = m-n;
    if(abs(dif) == 1){
        if(dif == 1) printf("Dr. Chaz will have %d piece of chicken left over!\n", m-n); 
        if(dif == -1) printf("Dr. Chaz needs %d more piece of chicken!\n", -dif);  // n > m
    }
    else{
        if(dif > 0) printf("Dr. Chaz will have %d pieces of chicken left over!\n", m-n); 
        if(dif < 0) printf("Dr. Chaz needs %d more pieces of chicken!\n", -dif);  // n > m
    }
    return 0;
}