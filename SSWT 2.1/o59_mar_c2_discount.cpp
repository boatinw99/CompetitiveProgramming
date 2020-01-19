#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e4+9 ,LOG =log2(N)+1;
int par[N],rnk[N],tin[N],tout[N],times=0 ;
int up[N][LOG],mx[N][LOG],depth[N] ;
vector<pair<int,pii> > E,ntree ;
vector<pii> g[N];
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int u,int v)
{
    int pu=find(u),pv=find(v);
    if(pu==pv)return 0 ;
    if(rnk[pu]>=rnk[pv])rnk[pu]+=rnk[pv],par[pv]=pu ;
    else rnk[pv]+=rnk[pu],par[pu]=pv ;
    return 1 ;
}
void dfs(int u,int v)
{
    up[u][0]=v;
    depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        mx[u][i]=max(mx[u][i-1],mx[up[u][i-1]][i-1]);
    }
    tin[u]=++times;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            mx[it.fi][0]=it.se ;
            dfs(it.fi,u);
        }
    }
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int blift(int u,int cst)
{
    int ret = 0 ;
    for(int i=0;i<LOG;i++)
    {
        if((1<<i)&cst)
        {
            ret=max(ret,mx[u][i]);
            u=up[u][i];
        }
    }
    return ret ;
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
main()
{
    int n,m,u,v,x,i,j ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)par[i]=i ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> x ;
        E.push_back({x,{u,v}});
    }
    sort(E.begin(),E.end());
    for(auto it:E)
    {
        if(Union(it.se.fi,it.se.se))
        {
            g[it.se.fi].emplace_back(it.se.se,it.fi);
            g[it.se.se].emplace_back(it.se.fi,it.fi);
        }
        else ntree.push_back(it);
    }
    dfs(1,1);
    int ans=INT_MAX ;
    for(auto it:ntree)
    {
        int lca=findlca(it.se.fi,it.se.se);
        int ret = max(blift(it.se.fi,depth[it.se.fi]-depth[lca]),
                    blift(it.se.se,depth[it.se.se]-depth[lca]));
        ans=min(ans,it.fi-ret);
    }
    cout << ans+1 ;
}
