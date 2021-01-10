#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e6+9,LOG=log2(N)+1 ;
vector<int> g[N];
int up[N][LOG],depth[N],tin[N],tout[N],times=0,ans=2;
pii q[N],dia={2,3} ;
void dfs(int u,int v)
{
    depth[u]=depth[v]+1;
    up[u][0]=v;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])dfs(it,u);
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
void update(int u)
{
    if(Islca(dia.fi,u))dia.fi=u,ans++;
    else if(Islca(dia.se,u))dia.se=u,ans++;
    else
    {
        int lca1=findlca(u,dia.fi),lca2=findlca(u,dia.se);
        if(depth[u]+depth[dia.fi]-2*depth[lca1]>ans)
        {
            ans=depth[u]+depth[dia.fi]-2*depth[lca1];
            dia.se=u ;
        }
        else if(depth[u]+depth[dia.se]-2*depth[lca2]>ans)
        {
            ans=depth[u]+depth[dia.se]-2*depth[lca2];
            dia.fi=u;
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n=4,m,i,j,x,y,u,v ;
    cin >> m;
    g[1].emplace_back(2);
    g[1].emplace_back(3);
    g[1].emplace_back(4);
    for(i=1;i<=m;i++)
    {
        cin >> x ;
        g[x].emplace_back(n+1);
        g[x].emplace_back(n+2);
        q[i]={n+1,n+2};
        n+=2;
    }
    tout[0]=INT_MAX ;
    dfs(1,0);
    for(i=1;i<=m;i++)
    {
        update(q[i].fi);
        cout << ans << '\n' ;
    }
}
