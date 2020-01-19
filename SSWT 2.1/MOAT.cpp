#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , LOG=log2(N)+1;
vector<int> G[N];
int up[N][LOG];
int tin[N],tout[N],times=0;
void dfs(int u,int v)
{
    up[u][0]=v;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:G[u])if(it!=v)dfs(it,u);
    tout[u]=++times;
}
bool Islca(int u,int v){return tin[u]<=tout[v]&&tout[u]>=tout[v];}
int findlca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)
        if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
bool qans(int u,int v,int k)
{
    int lca ;
    if(Islca(u,v))
    {
        if(Islca(u,k)&&Islca(k,v))return 1;
    }
    else if(Islca(v,u))
    {
        if(Islca(v,k)&&Islca(k,u))return 1;
    }
    else
    {
        lca=findlca(u,v);

        if(Islca(lca,k)&&Islca(k,u))return 1;
        if(Islca(lca,k)&&Islca(k,v))return 1;
    }
    return 0 ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T,i,j,u,v,k ;
    cin >> n >> T;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1,1);
    while(T--)
    {
        cin >> u >> v >> k ;
        if(qans(u,v,k))cout << "YES" ;
        else cout << "NO";
        cout << '\n' ;
    }
}
