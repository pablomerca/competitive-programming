#include <iostream>
#include <cstring>
using namespace std;

// kattis judge - Popular vote
int main(){

    int T, votes[10];  // ojo se puede romper si declaramos arrays dentro del loop.
    scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        int maxVotes = -1e8, winner = -1, numVotes = 0;
        for(int i=0; i<n; i++) votes[i]=0; // reset n vote counters to 0.

        for(int i=0; i<n; i++){
            int votesPerCand; scanf("%d", &votesPerCand);
            votes[i] += votesPerCand; 
            numVotes += votesPerCand;
            if(votesPerCand > maxVotes){
                maxVotes = votesPerCand;
                winner = i+1; // cadidates have index starting in 1.
            }
        }

        // check how many candidates have the max amount of votes, to find ties.
        int tieCounter = 0;
        for(int i=0; i<n; i++) if(votes[i] == maxVotes) tieCounter++;

        if(tieCounter > 1) printf("no winner\n");  // tie
        else if(maxVotes > numVotes/2) printf("majority winner %d\n", winner); 
        else printf("minority winner %d\n", winner);
    }

    return 0;
}

// memset toma chars como segundo argumento, osea que le tengo que pasar '0' en vez de 0.
// igualmente, creo que llenaria un array de int con valores char, lo que romperia todo, mejor evitarlo!!!

