#include <iostream>
#include <deque>
using namespace std;

const int INF = 1e9;

int main(){
    int nA, nB;
    deque<int> A,B;

    while(scanf("%d %d", &nA, &nB), (nA || nB)){
    
        for(int i=0; i<nA; i++){
            int temp;
            scanf("%d", &temp);
            A.push_back(temp);
        }
        for(int i=0; i<nB; i++){
            int temp;
            scanf("%d", &temp);
            B.push_back(temp);
        }
        // agregamos los valores centinela al final de A y B.
        A.push_back(INF); B.push_back(INF);

        int counterA = 0, counterB = 0;
        while(!A.empty() && !B.empty()){

            int currA = A.front(), currB = B.front();
            if(currA == currB){
                while(!A.empty() && A.front()==currA) A.pop_front();
                while(!B.empty() && B.front()==currB) B.pop_front();
            }
            else if(currA < currB){
                counterA++;
                while(!A.empty() && A.front()==currA) A.pop_front();
            }
            else{
                counterB++;
                while(!B.empty() && B.front()==currB) B.pop_front();
            }
        }
        printf("%d\n", min(counterA, counterB));
    }

    return 0;
}