#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <set>

using namespace std;


const int INF = 1e9;

vector<list<pair<int, int>>> adj_out;
vector<list<pair<int, int>>> adj_in;   // este tiene las flechas invertidas xd
vector<int> memo;

vector<int> ds;
vector<int> dt;

int s, t;

// le agregue el adj de inpt para que 
void dijkstra(vector<list<pair<int,int>>>& adj, int s, vector<int> & d) {

    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    set<pair<int, int>> q;  // {prioridad, nodo}
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                // relax, actualizamos su prioridad (la bajamos)
                q.erase({d[to], to}); // ojo, esta notacion {}, creo q solo es legar para versiones desde c++17
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

}


int dp(int w){

    if(memo[w] != -INF) return memo[w];
    if(w == s) return 1;
    int n = adj_in.size();

    int count = 0;
    for(pair<int, int> data : adj_in[w]){
        int v = data.first;
        int peso = data.second;
        
        // si es una edge st eficiente, entonces llamo recursivamente por el extremo v.
        if(ds[t] == ds[v] + peso + dt[w]){ 
            count += dp(v);
        }
    }

    memo[w] = count;
    return memo[w];
}




int main(){

    int n, m;

    cin >> n >> m;
    adj_out = adj_in = vector<list<pair<int, int>>>(n);
    memo.assign(n, -INF);

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // u --> v   , w = w(u,v)
        adj_out[u].push_back(make_pair(v,w));
        adj_in[v].push_back(make_pair(u,w));
    }
    cin >> s >> t;
    
    dijkstra(adj_out, s, ds);
    dijkstra(adj_in, t, dt);

    int ans = dp(t);

    printf("%i\n", ans);

    return 0;
}