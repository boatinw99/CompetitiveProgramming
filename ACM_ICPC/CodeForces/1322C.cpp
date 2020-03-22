/* 
    DATE 22-03-20 
    Implement Time 14:51 -> 14:58 , 16:10 -> 16:33
    Duration : 27 min 
    open tutorial : partial 
    bug : empty vector<> bug 
*/ 
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 5e5+9 ; 
vector<int> g[N];
map<vector<int>,ll> mp ; 
ll a[N];
void init(int n) {
    for(int i=1;i<=n;i++) {
        g[i].clear();
    }
    mp.clear();
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--) {
        int n,m ; 
        cin >> n >> m ;
        init(n);
        for(int i=1;i<=n;i++) {
            cin >> a[i] ;
        }
        for(int i=1,u,v ;i<=m;i++) {
            cin >> u >> v; 
            g[v].emplace_back(u);
        }
        ll gc = 0 ; 
        for(int i=1;i<=n;i++) {
            sort(g[i].begin(),g[i].end());
            if(!g[i].empty())mp[g[i]]+=a[i];
        }
        for(auto it:mp) {
            gc = __gcd(gc,it.second);
        }
        cout << gc << '\n' ;
    }
    return 0; 
}