#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int l,r;
    scanf("%d %d", &l, &r);
    if(l==0 && r==0) printf("Not a moose\n");
    else{
        if(l == r) printf("Even %d\n", 2*l); 
        else printf("Odd %d\n", 2*max(l,r)); 
    }

    return 0;
}