#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 2e5+9 , LOG = log2(N)+1;
vector<pii> g[N];
int up[N][LOG],par[N],rnk[N],depth[N];
ll dist[N];
void dfs0(int u,int v)
{
    up[u][0]=v;
    depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it.fi!=v)dist[it.fi]=dist[u]+it.se,dfs0(it.fi,u);
}
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int u,int v,int cst)
{
    int pu=find(u),pv=find(v);
    if(pu==pv)return 0;
    if(rnk[pu]>=rnk[pv])rnk[pu]+=rnk[pv],par[pv]=pu,swap(u,v);
    else rnk[pv]+=rnk[pu],par[pu]=pv;
    dist[u]=dist[v]+cst;
    dfs0(u,v);
    g[u].emplace_back(v,cst);
    g[v].emplace_back(u,cst);
    return 1;
}
int blift(int u,int cst)
{
    for(int i=0;i<LOG;i++)if((1<<i)&cst)u=up[u][i];
    return u ;
}
int findlca(int u,int v)
{
    if(depth[u]>depth[v])swap(u,v);
    if(blift(v,depth[v]-depth[u])==u)return u ;
    int l = -1 , r = depth[u] ;
    while(l+1<r)
    {
        int mid = l+r>>1 ;
        if(blift(u,depth[u]-mid)!=blift(v,depth[v]-mid))r=mid;
        else l=mid ;
    }
    return blift(u,depth[u]+1-r);
}
ll query(int u,int v)
{
    if(find(u)!=find(v))return -1 ;
    int lca = findlca(u,v);
    return dist[u]+dist[v]-2*dist[lca];
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,q ;
    cin >> n >> q ;
    for(int i=1;i<=n;i++)par[i]=i,rnk[i]=1;
    ll ans = 0 ;
    while(q--)
    {
        int typ,u,v,x ;
        cin >> typ >> u >> v ;
        u=(u+ans)%n+1;
        v=(v+ans)%n+1;
        if(typ==1)
        {
            cin >> x;
            Union(u,v,x);
        }
        else
        {
            ans = query(u,v);
            cout << ans << '\n' ;
        }
    }
    return 0 ;
}
