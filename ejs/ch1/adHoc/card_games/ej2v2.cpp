#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;


int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        string Jane, John, fu_jane, fu_john;
        int deckSize = Jane.size()*2;
        stack<char> fd_jane, fd_john;
        cin >> Jane >> John;

        for(int i=Jane.size(); i>=0; i--){
            fd_jane.push(Jane[i]);
            fd_john.push(John[i]);
        }

        for(int i=0; i<1000; i++){
            // john gana, jane no tiene mas cartas.
            if(fd_jane.empty() && fu_jane.empty()){
                printf("John wins.\n");
                break;
            }
            // jane gana, john no tiene mas cartas.
            if(fd_john.empty() && fu_john.empty()){
                printf("Jane wins.\n");
                break;
            }



        }

    }
}