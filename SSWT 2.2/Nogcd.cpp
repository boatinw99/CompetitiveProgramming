#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
int times = 0 ;
const int N = 1e5+9 ;
vector<int> g[N];
bool vst[N];
set<pii> s ;
void dfs0(int u,int v)
{
    vst[u]++;
    for(auto it:g[u])
    {
        if(it!=v&&!s.count(make_pair(u,it)))
        {
            cout << u << " " << it << " " << ++times << '\n' ;
            s.emplace(make_pair(u,it));
            s.emplace(make_pair(it,u));
            if(!vst[it])dfs0(it,u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,u,v ;
    cin >> n >> m ;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    return 0 ;
}
