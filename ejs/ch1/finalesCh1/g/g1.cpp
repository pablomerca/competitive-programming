#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;
    scanf("%d", &n);
    vector<int> R(n, 1);

    for(int i=0; i<n-1; i++){
        int dist;
        scanf("%d", &dist);
        R[dist + 1] = i+2;
    }

    for(int i=0; i<n-1; i++)
        printf("%d ", R[i]);
    printf("%d\n", R[n-1]);

    return 0;
}
