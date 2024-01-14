#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <math.h>


using namespace std;

int INF = 1e9;
vector<int> S;   // to store partial matching solutions in the backtracking
vector<pair<int,int>> coords;  // coordenates of the points in the map
double minVal = INF;     // this gets updated
int N;


double dist(pair<int, int>& p1, pair<int, int>& p2){    
    return hypot((double)(p1.first - p2.first), (double)(p1.second - p2.second));
}


void costo_Asignacion_Min(int i, double costoActual){

    if(i == N){
        minVal = min(minVal, costoActual);
        return;
    }
    if(costoActual > minVal) return;

    // si estoy tratando de asignar a alguien que ya fue asignado antes
    if(S[i] != -1){
        costo_Asignacion_Min(i+1, costoActual);
        return;
    }

    
    for(int j=0; j<N; j++){

        // si es que index j ya fue asignado o estoy haciendo auto-asignacion
        if(i == j || S[j] != -1) continue;

        // match the points
        S[i] = j;
        S[j] = i;

        double temp = dist(coords[i], coords[j]);
        costo_Asignacion_Min(i+1, costoActual + temp);  

        // backtrack, unmatch the points
        S[i] = -1;
        S[j] = -1;
    }

}



int main(){

    int nCase = 1;

    while(true){
        cin >> N;        // we want to make N matches of pairs of points
        if(N == 0) break;

        N *= 2;

        coords = vector<pair<int,int>>(N);
        S = vector<int>(N, -1);

        for(int i=0; i<N; i++){
            string name;  // this data is not relevant
            int x, y;
            cin >> name >> x >> y;

            coords[i] = make_pair(x, y); 
        }
        
        costo_Asignacion_Min(0, 0);
        double ans = minVal;

        printf("Case %i: %.2f\n", nCase++, ans);

        minVal = INF;
    }

    return 0;
}