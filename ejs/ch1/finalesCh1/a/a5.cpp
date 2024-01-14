#include <iostream>

using namespace std;

int main(){

    int n, p; 
    char str[30];
    scanf("%d %d", &n, &p);
    while(n--)
        scanf("%s", str);

    printf("%d\n", p);
    return 0;
}