//Strongly Connected Component (Tarjan)

#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 5 ;
vector < int > g[N], backup;
vector < vector < int > > comp ;
int low[N], in[N], used[N], cur ;

void Tarjan(int s) {
    used[s] = 1 ;
    low[s] = in[s] = ++cur ;
    backup.push_back(s) ;
    for(int i : g[s]) {
        if(!used[i])
            Tarjan(i) ;
        else
            low[s] = min(low[i], low[s]) ;
    }
    if(low[s] == in[s]) {
        vector < int > v ;
        while(1) {
            v.push_back((int)backup.back()) ;
            backup.pop_back() ;
            if((int)backup.back() == s)
                break ;
        }
        comp.push_back(v) ;
    }
}

int main() {
    int n, m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; ++i) {
        int x, y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
    }
    for(int i = 1 ; i <= n ; ++i)
        if(!used[i])
            Tarjan(i) ;
    return 0 ;
}

