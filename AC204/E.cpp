#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
const ll INF = 1e18;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
vector<vector<array<int, 3>>> adj(N);

void dijstral(vector<ll> &dist){
    dist[0] = 0;
    minpq<pair<ll, int>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        int cur_node = pq.top().second;
        ll cur_time = pq.top().first;
        pq.pop();
        if(dist[cur_node] != cur_time) continue;
        for(array<int, 3> next_edge: adj[cur_node]){
            int next_node = next_edge[0];
            ll c = next_edge[1], d = next_edge[2];
            ll nxt = sqrt(d);
            for(ll j = max(cur_time, nxt -2); j <= nxt + 2; j++){
                if(dist[next_node] > j + c + (d / (j + 1))){
                    dist[next_node] = j + c + (d / (j + 1));
                    pq.push({dist[next_node], next_node});
                }
            }
            if(cur_time > nxt + 2){
                ll temp = cur_time + c + (d / (cur_time + 1));
                if(dist[next_node] > temp){
                    dist[next_node] = temp;
                    pq.push({dist[next_node], next_node});
               }
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m); 
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a; --b;
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }
    vector<ll> dist(n, INF);
    dijstral(dist);
    printf("%lld\n", dist[n] == INF ? -1ll : dist[n-1]);
    return 0;
}