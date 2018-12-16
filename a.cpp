//Strongly Connected Component (Kosaraju)

#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 5 ;

vector < int > g[N], gr[N], comp, order ;
bool used[N] ;
vector < vector < int > > scc ;

void dfs1(int s) {
    used[s] = 1 ;
    for(int i : g[s])
        if(!used[i])
            dfs1(i) ;
    order.push_back(s) ;
}

void dfs2(int s) {
    used[s] = 1 ;
    comp.push_back(s) ;
    for(int i : gr[s])
        if(!used[i])
            dfs2(i) ;
}

int main() {
    int n, m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; ++i) {
        int x, y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    for(int i = 1 ; i <= n ; ++i)
        if(!used[i])
            dfs1(i) ;
    memset(used, 0, sizeof used) ;
    for(int i = (int)order.size() - 1 ; i >= 0 ; --i) {
        int u = order[i] ;
        if(used[u])
            continue ;
        dfs2(u) ;
        scc.push_back(comp) ;
        comp.clear() ;
    }
    return 0 ;
}
