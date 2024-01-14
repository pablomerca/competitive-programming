#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int N, t;
    scanf("%d %d", &N, &t);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    switch (t) {
        case 1:{
            printf("7\n");
            break;
        }
        case 2:{
            if(A[0] > A[1]) printf("Bigger\n");
            else if(A[0] == A[1]) printf("Equal\n");
            else printf("Smaller\n");
            break;
        }
        case 3:{
            sort(A.begin(), A.begin() + 3);
            printf("%d\n", A[1]);
            break;
        }
        case 4:{
            long long sum = 0;  // since numbers can be really big 32 bit non neg, signed ints.
            for(int i=0; i<N; i++) sum += A[i];
            printf("%lld\n", sum);
            break;
        }
        case 5:{
            long long sumPair = 0;  // to avoid overflow.
            for(int i=0; i<N; i++) if(A[i]%2==0) sumPair += A[i];
            printf("%lld\n", sumPair);
            break;
        }
        case 6:{
            for(int i=0; i<N; i++) printf( "%c", ('a' + (A[i]%26)) );
            printf("\n");
            break;
        }
        case 7:{
            int i = 0;
            while(1){
                if(i>=N){
                    printf("Out\n");
                    break;
                }
                if(i==-1){
                    printf("Cyclic\n");
                    break;
                }
                if(i==N-1){
                    printf("Done\n");
                    break;
                }
                // now we know that i is a safe index
                int next_i = A[i];
                A[i] = -1;
                i = next_i;
            }
            break;
        }
    }

    return 0;
}


// things to remember: 
// - when declaring a variable inside a case of a switch statement, it is necesary to wrap the
// case in "{}" to avoid scope conflicts.
// - when summing elements always make sure the sum variable has enough bytes to avoid overflow!!!