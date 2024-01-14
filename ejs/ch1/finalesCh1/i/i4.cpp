#include <iostream>
#include <stack>
using namespace std;

// uva 11786 - solved by Pablo Mercado
// easy stack solution.
int main(){
    int T;
    scanf("%d\n", &T);  // must consume char \n before entering the loop
    while(T--){
        stack<int> S;   // watch out, this should be int, not char.
        char ch;
        int i=0, ct = 0; 
        while(scanf("%c", &ch)!=EOF && ch!='\n'){
            if(ch == '\\') S.push(i);
            else if(ch == '/' && !S.empty()){
                ct += i - S.top();
                S.pop();
            } 
            i++;
        }
        printf("%d\n", ct);
    }
    return 0;
}