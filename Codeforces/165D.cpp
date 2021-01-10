#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<int> g[N];
set<int> s[N];
pii edge[N];
int depth[N];
int par[N];
void dfs(int u,int v,int p)
{
    depth[u]=depth[v]+1;
    par[u]=p ;
    for(auto it:g[u])if(it!=v)dfs(it,u,p);
}
void Eedge(int p)
{
    int u = edge[p].fi,v=edge[p].se ;
    if(depth[u]>depth[v])swap(u,v);
    s[par[v]].erase(depth[u]);
}
void Iedge(int p)
{
    int u = edge[p].fi,v=edge[p].se ;
    if(depth[u]>depth[v])swap(u,v);
    s[par[v]].insert(depth[u]);
}
int qans(int u,int v)
{
    if(depth[u]>depth[v])swap(u,v);
    if(par[u]==par[v]&&!s[par[u]].empty())
    {
        auto it = s[par[u]].lower_bound(depth[u]);
        if(it!=s[par[u]].end()&&*it<depth[v])return -1;
    }
    else if(!s[par[u]].empty()&&*s[par[u]].begin()<depth[u])return -1;
    else if(!s[par[v]].empty()&&*s[par[v]].begin()<depth[v])return -1;
    if(par[u]==par[v])return depth[v]-depth[u];
    return depth[u]+depth[v];
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int cent = 1,n,i,j,T,u,v,cnt=1,t ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        edge[i]={u,v};
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(g[i].size()>2)
        {
            cent=i ;
            break;
        }
    }
    for(auto it:g[cent])dfs(it,cent,cnt++);
    cin >> T ;
    while(T--)
    {
        cin >> t ;
        if(t==1)cin >> u,Eedge(u) ;
        else if(t==2)cin >> u,Iedge(u) ;
        else
        {
            cin >> u >> v ;
            cout << qans(u,v) << '\n' ;
        }
    }

}
