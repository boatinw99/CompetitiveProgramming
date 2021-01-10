#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
const int N = 1e5+9 , LOG = log2(N);
vector<pii> G[N];
int up[N][LOG+1];
int val[N];
int path[N];
int tin[N],tout[N];
int times=1 ;
void dfs(int u,int v)
{
    tin[u]=++times;
    up[u][0]=v;
    for(int i=1;i<=LOG;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:G[u])
    {
        if(it.first!=v)
        {
            dfs(it.first,u);
        }
    }
    tout[u]=++times ;
}
void dfs2(int u,int v)
{
    for(auto it:G[u])
    {
        if(it.first!=v)
        {
            dfs2(it.first,u);
            path[it.second]=val[it.first];
            val[u]+=val[it.first];
        }
    }
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG;i>=0;i--)
    {
        if(!Islca(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j,u,v,T ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].push_back({v,i});
        G[v].push_back({u,i});
    }
    dfs(1,1);
    cin >> T;
    while(T--)
    {
        cin >> u >> v ;
        val[u]++; val[v]++; val[findlca(u,v)]-=2;
    }///
    dfs2(1,1);
    for(i=1;i<n;i++)cout << path[i] << " ";
}
