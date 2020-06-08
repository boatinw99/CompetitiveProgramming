#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+9 ; 
typedef pair<int,int> pii ; 
#define fi first
#define se second 
vector<int> g[N];
vector<pii> V ; 
vector<int> ans ; 
int n,m ;
int val[N];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=1;i<=m;i++) {
        int u,v ; 
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++) {
        int x ; 
        cin >> x ;
        val[i]=x;
        V.emplace_back(x,i);
    }
    sort(V.begin(),V.end());
    bool good = 1 ;
    for(int i=1;i<=n;i++) {
        int mx = 0 ; 
        set<int> s ; 
        for(auto it:g[i]) {
            if(val[it]==val[i]) {
                good = 0 ; 
            }
            else if(val[it]<val[i])s.insert(val[it]);
        }
        if(s.size()!=val[i]-1||(!s.empty()&&*s.rbegin()!=val[i]-1)) {
            good = 0 ;
        }
    }
    if(good) {
        for(auto it:V) {
            cout << it.se << " " ;
        }
    }
    else {
        cout << -1 << '\n' ; 
    }
    return 0 ;
}