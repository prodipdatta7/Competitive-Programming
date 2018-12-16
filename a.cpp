#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 5 ;
typedef pair< int, int > pii ;
vector< vector< pii > > g;
bool vis[N] ;

void dijkstra(int s, int n) {
    std::vector< int > dist(n + 1, INT_MAX) ;
    vis[s] = 1 ;
    dist[s] = 0 ;
    priority_queue< pii > pq ;
    pq.push({0, s}) ;
    while(!pq.empty()) {
        int x = pq.top().second ;
        pq.pop() ;
        vis[x] = 1 ;
        for(pii i : g[x]) {
            if(vis[i.first] == 1)
                continue ;
            if(dist[i.first] > dist[x] + i.second) {
                dist[i.first] = dist[x] + i.second ;
                pq.push({-dist[i.first], i.first}) ;
            }
        }
    }
}

int main() {
    int n, m ;
    cin >> n >> m ;
    g.resize(n + 1) ;
    for(int i = 1 ; i <= m ; ++i) {
        int x, y, z ;
        cin >> x >> y >> z ;
        g[x].push_back({y, z}) ;
        g[y].push_back({x, z}) ;
    }
    dijkstra(1, n) ;
}
