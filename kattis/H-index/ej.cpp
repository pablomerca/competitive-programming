#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findHIndex(vector<int> &V){

    // if(V.size() == 1) return ((V[0] == 1)?1:0);  // {100} rta = 1, ya que hay justo un index con valor mayor igual a 1. Ta mal la linea!


    int n = V.size();
    int res = 0;

    for(int i=n-1; i>=0; i--){
        if(V[i] >= n-i) res = n-i;
        else break;
    }

    return res;
}


int main(){

    int n;
    cin >> n;
    vector<int> V(n);

    for(int i = 0; i < n; i++)
        cin >> V[i];

    sort(V.begin(), V.end());

    int ans = findHIndex(V); 
    cout << ans << endl;

    return 0;
}
