#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int n, k;
    bool seen_pos[1000];
    cin>> n >> k;
    for(int i=0; i<n; i++) seen_pos[i] = false;

    unordered_set<string> seen_card;
    int unseen_positions = n, unmatched_pairs = n/2, res = 0;

    for(int i=0; i<k; i++){
        string c1, c2;
        int p1, p2;    
        cin>> p1 >> p2 >> c1 >> c2;

        if(!seen_pos[p1-1]){
            seen_pos[p1-1] = true;
            unseen_positions--;
            if(seen_card.count(c1) == 0) seen_card.insert(c1);
            else res++, unmatched_pairs--;
        }
        if(!seen_pos[p2-1]){
            seen_pos[p2-1] = true;
            unseen_positions--;
            if(seen_card.count(c2) == 0) seen_card.insert(c2);
            else res++, unmatched_pairs--;
        }
        if(c1 == c2) res--;  // to avoid counting pairs that were previously discovered.
    }

    if(unseen_positions == 2 && unmatched_pairs == 1) res++;  // 2 cards unturned and 1 unmatched pair remains.
    else if(unseen_positions == unmatched_pairs) res += unseen_positions;  // X unturned cards and X unmatched pairs remain.
    cout<< res << endl;
    return 0;
}