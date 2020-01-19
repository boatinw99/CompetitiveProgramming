#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 , W = 1e7+9 ,md=33331,LOG=log2(N)+1,inf = 1e9;
vector<pii> g[N];
vector<pair<int,pii> > edge ;
int p[W],par[N],rnk[N],a[N],up[N][LOG],tin[N],tout[N],times=0;
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
void pre()
{
    p[0]=1;
    for(int i=1;i<W;i++)p[i]=p[i-1]*2%md ;
}
void dfs0(int u,int v,int cst)
{
    tin[u]=++times;
    up[u][0]=v;
    a[u]=cst;
    ///printf("aaaa %d %d \n",u,a[u]);
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it.fi!=v)dfs0(it.fi,u,(cst+p[it.se])%md);
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,q,i,j,u,v,x ;
    cin >> n >> m >> q ;
    pre();
    for(i=1;i<=n;i++)par[i]=i;
    while(m--)
    {
        cin >> u >> v >> x ;
        edge.push_back({x,{u,v}});
    }
    sort(edge.begin(),edge.end());
    for(auto it:edge)
    {
        if(Union(it.se.fi,it.se.se))
        {
            g[it.se.fi].emplace_back(it.se.se,it.fi);
            g[it.se.se].emplace_back(it.se.fi,it.fi);
        }
    }
    tout[0]=inf ;
    dfs0(1,0,0);
    while(q--)
    {
        cin >> u >> v ;
        int lca=findlca(u,v);
        cout << (a[u]+a[v]-2*a[lca]+md+md)%md << '\n';
    }


}
