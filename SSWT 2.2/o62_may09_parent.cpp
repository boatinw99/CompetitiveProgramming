#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ,LOG = log2(N)+1 ,inf = 2e9 ;
vector<int> g[N];
int up[N][LOG],depth[N],kng[N],p[N],sz[N],tin[N],tout[N],times=0;
struct q
{
    int typ,x,y ;
};
vector<q> query ;
int find(int u)
{
    return u==p[u]?u:p[u]=find(p[u]);
}
bool Union(int u,int v)
{
    u = find(u),v=find(v);
    int nw = kng[v];
    if(u==v)return 0 ;
    if(sz[u]>sz[v])swap(u,v);
    sz[v]+=sz[u];
    p[u]=v;
    kng[v]=nw ;
    return 1 ;
}
void dfs0(int u,int v)
{
    up[u][0]=v;
    depth[u]=depth[v]+1;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])
    {
        if(it!=v)dfs0(it,u);
    }
    tout[u]=++times;
}
int blift(int u,int cst)
{
    for(int i=1;i<LOG;i++)
    {
        if((1<<i)&cst)u=up[u][i];
    }
    return u ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
int getans(int u,int v,int x)
{
    if(depth[u]>depth[v])swap(u,v);
    int lcau = findlca(u,x),lcav=findlca(v,x);
    //printf("chk %d %d (%d %d %d)\n",lcau,lcav,u,v,x);
    if(lcau==lcav)return u ;
    else return v ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,typ ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)p[i]=i,kng[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v ;
        cin >> typ >> u ;
        if(typ==1)
        {
            cin >> v ;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            query.push_back({1,u,v});
        }
        else if(typ==2)
        {
            query.push_back({2,u,inf});
        }
        else
        {
            cin >> v ;
            query.push_back({3,u,v});
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(tin[i]==0)dfs0(i,i);
    }
    for(auto it:query)
    {
        if(it.typ==1)
        {
            Union(it.x,it.y);
        }
        else if(it.typ==2)
        {
            int u = find(it.x);
            kng[u] = it.x ;
        }
        else
        {
            int king = kng[find(it.x)];
            cout << getans(it.x,it.y,king) << '\n';
        }
    }

}
