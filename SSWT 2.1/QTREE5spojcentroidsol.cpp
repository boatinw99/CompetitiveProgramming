#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , LOG = log2(N)+1 ,MAX = 1e9 ;
vector<int> g[N];
multiset<int> mt[N];
int up[N][LOG];
int par[N],sub[N],depth[N],clr[N];
int tin[N],tout[N],times=0,nn;
bool b[N];
void dfs0(int u,int v)
{
    up[u][0]=v; depth[u]=depth[v]+1; tin[u]=++times;
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
void dfs1(int u,int v)
{
    sub[u]=1;nn++;
    for(auto it:g[u])if(it!=v&&!b[it])dfs1(it,u),sub[u]+=sub[it];
}
int dfs2(int u,int v)
{
    for(auto it:g[u])if(it!=v&&!b[it]&&sub[it]>nn/2)return dfs2(it,u);
    return u ;
}
void decompose(int root,int p)
{
    nn=0; dfs1(root,root);
    int cen=dfs2(root,root); par[cen]=p; b[cen]++;
    for(auto it:g[cen])if(!b[it])decompose(it,cen);
}
void E(multiset<int> &a,int val){auto it=a.find(val); a.erase(it); }
void color(int u)
{
    int x=u ;
    if(clr[u]==0)while(x)E(mt[x],dist(x,u)),x=par[x];
    else while(x)mt[x].insert(dist(x,u)),x=par[x];
    clr[u]^=1;
}
int qans(int u)
{
    int x = u,min1=MAX ;
    while(x)min1=min(min1,*mt[x].begin()+dist(x,u)),x=par[x];
    return (min1<MAX)?min1:-1;
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
        g[u].emplace_back(v); g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)mt[i].insert(MAX),clr[i]=1;
    dfs0(1,1); decompose(1,0);
    cin >> T ;
    //for(i=1;i<=n;i++)
    while(T--)
    {
        cin >> u >> v ;
        if(u==0)color(v);
        else cout << qans(v) << '\n';
    }
}
