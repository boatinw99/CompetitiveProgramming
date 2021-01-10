#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1 ;
vector<pii> g[N];
set<int> s;
int up[N][LOG],tin[N],tout[N],pos[N*2];
int mn=0,times=0;
ll dist[N],ans=0 ;
void dfs(int u,int v)
{
    tin[u]=++times ;
    pos[times]=u ;
    up[u][0]=v;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it.fi!=v)
        dist[it.fi]=dist[u]+it.se,dfs(it.fi,u);
    tout[u]=++times ;
    pos[times]=u ;
}
bool Isa(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
bool nochild(int u)
{
    auto it = s.lower_bound(tin[u]);
    if(it==s.end())return 1 ;
    if(tout[u]<=*it)return 1;
    return 0 ;
}
int findlca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)if(!Isa(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int lift(int u)
{
    for(int i=LOG-1;i>=0;i--)if(nochild(up[u][i]))u=up[u][i];
    return up[u][0];
}
int alllca(int u)
{
    for(int i=LOG-1;i>=0;i--)
    {
        int tmp=up[u][i];
        auto it=s.lower_bound(tout[tmp]);
        if(it!=s.end())u=up[u][i];
    }
    return up[u][0];
}
void build(int u)
{
    if(s.empty())mn=u;
    else if(Isa(u,mn))ans+=dist[mn]-dist[u],mn=u;
    else if(Isa(mn,u))
    {
        if(nochild(u))ans+=dist[u]-dist[lift(u)];
    }
    else
    {
        int lca=findlca(u,mn);
        ans+=dist[u]+dist[mn]-2*dist[lca];
        mn=lca;
    }
    s.insert(tin[u]);
}
void destroy(int u)
{
    s.erase(tin[u]);
    if(s.empty());
    else if(!nochild(u)&&u!=mn);
    else if(!nochild(u))
    {
        int tmp=pos[*s.begin()];
        auto it=s.lower_bound(tout[tmp]);
        if(it!=s.end())tmp=alllca(tmp);
        ans-=dist[tmp]-dist[mn];
        mn=tmp;
    }
    else
    {
        int tmp=lift(u);
        ans-=dist[u]-dist[tmp];
        if(tmp==mn)
        {
            tmp = pos[*s.begin()];
            auto it=s.lower_bound(tout[tmp]);
            if(it!=s.end())tmp = alllca(tmp);
            ans-=dist[tmp]-dist[mn];
            mn=tmp ;
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,T,u,v,wi  ;
    char c ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> wi ;
        g[u].emplace_back(v,wi);
        g[v].emplace_back(u,wi);
    }
    dfs(1,1);
    cin >> T ;
    while(T--)
    {
        cin >> c ;
        if(c=='+')cin >> u , build(u);
        else if(c=='-')cin >> u , destroy(u);
        else cout << ans << '\n' ;
    }
}
