#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9,LOG=log2(N)+1 ;
vector<int> g[N];
int up[N][LOG],tin[N],tout[N],times=0;
void dfs(int u,int v)
{
    up[u][0]=v;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it : g[u])if(it!=v)dfs(it,u);
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
int qans(int r,int u,int v)
{
    int lca=findlca(u,v),lcau=findlca(u,r),lcav=findlca(v,r) ;
    if(Islca(r,lca))return lca ;
    if(lcau==lcav&&lcau==lca)return lca ;
    if(lcau==lca)return lcav ;
    if(lcav==lca)return lcau ;
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,u,v,i,j,r,T ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1);
    cin >> T ;
    while(T--)
    {
        cin >> r >> u >> v ;
        cout << qans(r,u,v) << '\n' ;
    }
}
