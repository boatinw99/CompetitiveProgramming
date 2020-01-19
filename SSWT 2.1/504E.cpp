#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 3e5+9 , LOG=log2(N)+1 ;
const ll PB=98765431 ;
vector<int> g[N];
ll ex[N],dist[2][N][LOG] ;///up & down ;
int par[N][LOG],tin[N],tout[N],depth[N],ex2[LOG],times=0;
char a[N];
void dfs(int u,int v)
{
    tin[u]=++times ;
    par[u][0]=v;
    depth[u]=depth[v]+1;
    dist[0][u][0]=dist[1][u][0]=a[v];
    for(int i=1;i<LOG;i++)
    {
        par[u][i]=par[par[u][i-1]][i-1];
        dist[0][u][i]=dist[0][u][i-1]*ex[ex2[i-1]]+dist[0][par[u][i-1]][i-1];
        dist[1][u][i]=dist[1][u][i-1]+dist[1][par[u][i-1]][i-1]*ex[ex2[i-1]];
    }
    for(auto it:g[u])if(it!=v)dfs(it,u);
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
    for(int i=LOG-1;i>=0;i--)if(!Islca(par[u][i],v))u=par[u][i];
    return par[u][0];
}
int kth(int u,int cst)
{
    for(int i=0;i<LOG;i++)if(ex2[i]&cst)u=par[u][i];
    return u ;
}
ll lift(int u,int cst)
{
    ll hash = 0,tmp=ex[cst]*a[u] ;
    for(int i=0;i<LOG;i++)
    {
        if(ex2[i]&cst)
        {
            hash=hash*ex[ex2[i]]+dist[0][u][i];
            u=par[u][i];
        }
    }
    return hash+tmp ;
}
ll liftinv(int u,int cst)
{
    ll hash = 0,tmp=a[u],pre=1;
    for(int i=0;i<LOG;i++)
    {
        if(ex2[i]&cst)
        {
            hash=hash+dist[1][u][i]*pre;
            u=par[u][i];
            pre=ex[ex2[i]];
        }
    }
    return hash*PB+tmp ;
}
ll finddist(int u,int v,int lca)
{
    if(Islca(u,v))return lift(v,depth[v]-depth[u]);
    if(Islca(v,u))return lift(u,depth[u]-depth[v]);
    ll l = lift(u,depth[u]-depth[lca]);
    ll r = liftinv(v,depth[v]-depth[lca]-1);
    return l*ex[depth[v]-depth[lca]]+r ;
}
int findnode(int u,int v,int lca,int cst)
{
    if(Islca(u,v))return kth(v,depth[v]-depth[u]-cst+1);
    if(Islca(v,u))return kth(u,cst-1);
    if(depth[u]-depth[lca]+1>=cst)return kth(u,cst-1);
    else return kth(v,depth[v]-depth[lca]-cst+(depth[u]-depth[lca]+1));
}
ll qans(int u,int v,int x,int y)
{
    int lca1=findlca(u,v),lca2=findlca(x,y),l=0;
    int r = min(depth[u]+depth[v]-2*depth[lca1],
                depth[x]+depth[y]-2*depth[lca2])+2;
    if(u==v||x==y)return a[u]==a[x];
    while(l+1<r)
    {
        int mid=l+r>>1;///numb
        int tmp1=findnode(u,v,lca1,mid),tmp2=findnode(x,y,lca2,mid) ;
        if(finddist(u,tmp1,lca1)==finddist(x,tmp2,lca2))l=mid;
        else r=mid ;
    }
    return l ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v,T ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i];
    ex[0]=ex2[0]=1;
    for(i=1;i<N;i++)ex[i]=ex[i-1]*PB;
    for(i=1;i<LOG;i++)ex2[i]=ex2[i-1]*2;
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
        cin >> u >> v >> i >> j ;
        cout << qans(u,v,i,j) << '\n' ;
    }
}
