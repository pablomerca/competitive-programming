#include <iostream>
#include <algorithm>
using namespace std;


int a_play(int a[], int b_play){  // esto ya no devuleve el ixd, sino la carta jugada por a.
    int res_idx = -1, res = 100;
    for(int i=0; i<3; i++) if(a[i] > b_play && a[i] < res){
        res_idx = i;
        res = a[i];
    } 
    if(res_idx > -1){
        res = a[res_idx];
        a[res_idx] = 0;
    } 
    return res;
}

int main(){

    int a[3], b1, b2;
    bool played[53];  // el primer casillero es basura, para que indexe en 1.
    while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b1, &b2), b1){
        if(b1 > b2) swap(b1, b2);
        for(int i=0; i<53; i++) played[i]=false;

        played[a[0]] = true;
        played[a[1]] = true;
        played[a[2]] = true;
        played[b1] = true;
        played[b2] = true;

        int a_points = 0, b_points = 0;

        // primer round, b plays b1, its lowest card.
        if(a_play(a, b1) < 100) a_points++;
        else{
            a_play(a, 0); // juega el menor valor mayor a 0, osea el minimo de las que tiene disponibles
            b_points++;
        }

        // second round, b plays b2, its highest card so far.
        if(a_play(a, b2) < 100) a_points++;
        else{
            a_play(a, 0); // juega el menor valor mayor a 0, osea el minimo de las que tiene disponibles
            b_points++;
        }
        
        int res;
        if(a_points == 2){
            printf("-1\n");
            continue;
        }
        else if(b_points == 2) res = 1;
        else res = a_play(a, 0);    // 3rd round (b_points == 1), a plays her last card 

        for(; res<=52; res++) if(!played[res]) break;
        printf("%d\n", (res > 52 ? -1 : res));  // 52 is not a valid card value.
    }
    return 0;
}
