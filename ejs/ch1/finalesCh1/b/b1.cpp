#include <iostream>

using namespace std;

int main(){
    
    int n;
    int counter = 0;
    scanf("%d", &n);
    while(n--)
        printf("%d Abracadabra\n", ++counter);
        
    return 0;
}