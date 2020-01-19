#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1;
int up[N][LOG],mx[N][LOG],tin[N],tout[N],times=0,depth[N],rnk[N];
int par[N];
vector<pii> tree[N],outtree[N];
vector<pair<int,pii> > g;
int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
bool Union(int u,int v)
{
    int pu=find(u),pv=find(v);
    if(pu==pv)return 0;
    if(rnk[pu]>=rnk[pv])rnk[pu]+=rnk[pv],par[pv]=pu;
    else rnk[pv]+=rnk[pu],par[pu]=pv;
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
    tin[u]=++times ;
    for(auto it:tree[u])
    {
        if(it.fi!=v)
        {
            mx[it.fi][0]=it.se;
            dfs(it.fi,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int blift(int u,int cst)
{
    int x=0;
    for(int i=0;i<LOG;i++)
    {
        if((1<<i)&cst)
        {
            x=max(x,mx[u][i]);
            u=up[u][i];
        }
    }
    return x ;
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u;
    if(Islca(v,u))return v;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
int qans(int u,int v)
{
    int lca=findlca(u,v);
    return max(blift(u,depth[u]-depth[lca]),blift(v,depth[v]-depth[lca]));
}
main()
{
    int n,m,u,v,x,i,j ;
    ll mst=0;
    cin >> n >> m ;
    for(i=1;i<=n;i++)par[i]=i;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> x ;
        g.push_back({x,{u,v}});
    }
    sort(g.begin(),g.end());
    for(auto it:g)
    {
        if(Union(it.se.fi,it.se.se))
        {
            tree[it.se.fi].emplace_back(it.se.se,it.fi);
            tree[it.se.se].emplace_back(it.se.fi,it.fi);
            mst+=it.fi ;
        }
        else
        {
            outtree[it.se.fi].emplace_back(it.se.se,it.fi);
        }
    }
    int ans=INT_MAX ;
    dfs(1,1);
    for(i=1;i<=n;i++)
    {
        for(auto it:outtree[i])
        {
            int tmp=qans(i,it.fi);
            if(it.se!=tmp)ans=min(ans,it.se-tmp);
        }
    }
    cout << mst+ans;
}
