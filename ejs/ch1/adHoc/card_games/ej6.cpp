#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;

void shuff(int* deck, int* shuffled, bool out){
    int l1 = 0, h2 = n;
    int h1 = (n/2)-1, l2 = (n/2);  // aplica para n par y n impar in
    if(n%2 == 1 && out){
        h1++, l2++;                // caso n impar out
    }

    if(!out) swap(l1, l2);  // para que l1 siempre sea el index de la mitad con prioridad.
    for(int i=0; i<n; i++)
        shuffled[i] = deck[(i%2==0 ? l1++ : l2++)];  // l1 es siempre el que tiene prioridad...
}

bool check(int* deck){
    for(int i=0; i<n; i++)
        if(deck[i] != i) return false;
    return true;
}

int main(){
    
    int deck[1000], shuffled[1000];
    string type;
    cin>> n >> type;
    for(int i=0; i<n; i++) deck[i] = i;
    int res = 0;
    do{
        res++;
        shuff(deck, shuffled, type == "out");
        swap(deck, shuffled);
    }
    while(!check(deck));

    cout<< res <<endl;
    return 0;
}