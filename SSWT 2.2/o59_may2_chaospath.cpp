#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,ll> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<pii> g[N],g1[N];
int sub[N],n;
ll mx = 0,ans=0 ;
bool vst[N];
void dfs0(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it=g[u].begin();it!=g[u].end();it++)
    {
        if(!vst[it->fi])
        {
            dfs0(it->fi);
            sub[u]+=sub[it->fi];
            it->se = 1ll*sub[it->fi]*(n-sub[it->fi]);
            g1[u].emplace_back(it->fi,it->se);
            g1[it->fi].emplace_back(u,it->se);
        }
    }
    vst[u]=0 ;
}
void dfs1(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])if(!vst[it.fi])dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it.fi!=v&&!vst[it.fi]&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,ll cst)
{
    vst[u]++;
    ans=max(ans,mx+cst);
    for(auto it:g[u])if(!vst[it.fi])dfs3(it.fi,cst+it.se);
    vst[u]=0 ;
}
void dfs4(int u,ll cst)
{
    vst[u]++;
    mx=max(mx,cst);
    for(auto it:g[u])if(!vst[it.fi])dfs4(it.fi,cst+it.se);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    mx=0 ;
    vst[ctd]++;
    for(auto it:g[ctd])
    {
        if(!vst[it.fi])dfs3(it.fi,it.se),dfs4(it.fi,it.se);
    }
    for(auto it:g[ctd])if(!vst[it.fi])dcp(it.fi);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v,0);
        g[v].emplace_back(u,0);
    }
    dfs0(1);
    for(i=1;i<=n;i++)swap(g[i],g1[i]);
    dcp(1);
    cout << ans ;
}
