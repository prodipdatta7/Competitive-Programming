//Minimum Spanning Tree (Prims algo)

#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 5 ;
typedef pair< int, int > pii ;
vector< vector< pii > > g;
bool vis[N] ;

int Prims(int s, int n) {
    priority_queue< pii > pq ;
    pq.push({0, s}) ;
    int res = 0 ;
    while(!pq.empty()) {
        int x = pq.top().second ;
        pq.pop() ;
        int c = -pq.top().first ;
        if(!vis[x]) {
            res += c ;
            vis[x] = 1 ;
            for(pii i : g[x]) {
                pq.push({-i.second, i.first}) ;
            }
        }
    }
    return res ;
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
    int s ;
    cin >> s ;
    cout << Prims(s, n) << '\n' ;
}
