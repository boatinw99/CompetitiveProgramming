#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<int> g[N];
vector<pii> query[N];
int t[N],sub[N],tin[N],tout[N],times=0,pos[N],depth[N];
ll f[N],a[N];
void dfs0(int u)
{
    sub[u]=1;
    tin[u]=++times;
    pos[times]=u ;
    for(auto it:g[u])depth[it]=depth[u]+1,dfs0(it),sub[u]+=sub[it];
    tout[u]=times;
}
void dfs1(int u,bool kp)
{
    int mx=0,tmp=0;
    for(auto it:g[u])if(sub[it]>mx)mx=sub[it],tmp=it ;
    for(auto it:g[u])if(tmp!=it)dfs1(it,0);
    if(tmp)dfs1(tmp,1);
    t[depth[u]]++;
    for(auto it:g[u])if(it!=tmp)
    {
        for(int i=tin[it];i<=tout[it];i++)
        {
            t[depth[pos[i]]]++;
        }
    }
    for(auto it:query[u])
    {
        a[u]-=1ll*t[it.fi]*it.se;
    }
    if(!kp)
    {
        for(int i=tin[u];i<=tout[u];i++)
        {
            t[depth[pos[i]]]--;
        }
    }
}
void dfs2(int u)
{
    for(auto it:query[u])f[it.fi]+=it.se;
    for(auto it:g[u])dfs2(it);
    a[u]+=f[depth[u]];
    for(auto it:query[u])f[it.fi]-=it.se ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,x ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> u >> a[i] ;
        u++;
        g[u].emplace_back(i);
    }
    depth[1]=1;
    dfs0(1);
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> x ;
        u++;
        query[u].emplace_back(depth[u]+v,x);
    }
    dfs1(1,1);
    dfs2(1);
    for(i=1;i<=n;i++)cout << a[i] << '\n' ;
}
