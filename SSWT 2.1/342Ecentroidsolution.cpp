#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , LOG=log2(N)+1 ,MAX = 1e9 ;
vector<int>g[N];
int up[N][LOG],tin[N],tout[N],depth[N]; ///lca
int par[N],sub[N],ans[N];
int times=0,nn;
bool mark[N];
void dfs0(int u,int v)
{
    up[u][0]=v; tin[u]=++times; depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it!=v)dfs0(it,u);
    tout[u]=++times;
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v]; }
int lca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int dist(int u,int v)
{
    if(Islca(u,v))return depth[v]-depth[u];
    if(Islca(v,u))return depth[u]-depth[v];
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void dfs1(int u,int v) /// find sub
{
    sub[u]=1; nn++;
    for(auto it:g[u])if(it!=v&&!mark[it])dfs1(it,u),sub[u]+=sub[it];
}
int dfs2(int u,int v)
{
    for(auto it:g[u])if(it!=v&&sub[it]>nn/2&&!mark[it])return dfs2(it,u);
    return u ;
}
void decompose(int root,int p)
{
    nn=0; dfs1(root,p);
    int cen=dfs2(root,p); mark[cen]++; par[cen]=p;
    for(auto it:g[cen])if(!mark[it])decompose(it,cen);
}
void color(int u)
{
    int x = u ;
    while(x)ans[x]=min(ans[x],dist(u,x)),x=par[x];
}
int qans(int u)
{
    int x=u,min1=MAX;
    while(x)min1=min(min1,ans[x]+dist(x,u)),x=par[x];
    return min1;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T,i,j,u,v ;
    cin >> n >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v); g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)ans[i]=MAX;
    dfs0(1,1); decompose(1,0); color(1);
    while(T--)
    {
        cin >> u >> v ;
        if(u==1)color(v); else cout << qans(v) << '\n';
    }
}
