#include <iostream>
#include <cstring>
#include <list>
using namespace std;


int main(){
    char str[500], P[] = "luve"; 
    int P_size = 4;
    list<int> res;
    fgets(str, 499, stdin);
    char* it = str;
    char* temp;
    while(temp = strstr(it, P)){
        int index = temp - str;
        res.push_back(index);
        it = temp + P_size;
    }
    if(res.empty()) printf("-1");
    else for(int e : res) printf("%d ", e);
    printf("\n");
    return 0;
}



