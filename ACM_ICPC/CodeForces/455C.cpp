#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 3e5+9 ; 
vector<int> g[N] ;  
int par[N],sz[N];
bool vst[N];
pii val[N]; /// mn mx
pii compute(pii x,pii y)
{
    if(x.se>y.se)swap(x,y);
    pii ret = y ;
    ret.fi = max(ret.fi,x.se+1);
    if(ret.fi>ret.se)swap(ret.fi,ret.se);
    return ret ; 
}
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
void Union(int u,int v)
{
    u = find(u);
    v = find(v);
    if(u==v)return ; 
    pii x = val[u] , y = val[v];
    pii ret = compute(x,y);
    if(sz[u]>=sz[v])sz[u]+=sz[v],par[v]=u,val[u]=ret ;
    else sz[v]+=sz[u],par[u]=v,val[v]=ret ;
}
pii dfs_maxdep(int u,int v,int cst=0)
{
    pii ret = {cst,u};
    vst[u]++;
    for(auto it:g[u])
    {
        if(it!=v)ret=max(ret,dfs_maxdep(it,u,cst+1));
    }
    return ret ; 
}
pii getcenter(int x)
{
    int node_mx = dfs_maxdep(x,x).se;
    int longest = dfs_maxdep(node_mx,node_mx).fi;
    return {longest/2,longest-longest/2};
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,q ; 
    cin >> n >> m >> q ;
    for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v ; 
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        Union(u,v); /// be careful 
    }
    for(int i=1;i<=n;i++)
    {
        if(!vst[i])
        {
            val[find(i)]=getcenter(i);
        }
    }
    while(q--)
    {
        int typ,u,v ;
        cin >> typ ;
        if(typ==1)
        {
            cin >> u ;
            cout << val[find(u)].fi+val[find(u)].se << '\n' ;
        }
        else 
        {
            int u,v ; 
            cin >> u >> v ;
            Union(u,v);
        }
    }
    return 0 ; 
}