///14.29
#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,md=1e9+7;
vector<int> g[N];
int K,i,j,sub[N];
bool vst[N];
int dist[N];
int ans=0 ;
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs1(it),sub[u]+=sub[it];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&!vst[it]&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int cst)
{
    if(cst>K)return;
    ans=(ans+dist[K-cst])%md;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs3(it,cst+1);
    vst[u]=0;
}
void dfs4(int u,int cst,int add)
{
    dist[cst]+=add;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs4(it,cst+1,add);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    dist[0]++;
    vst[ctd]++;
    for(auto it:g[ctd])
    {
        if(!vst[it])
        dfs3(it,1),dfs4(it,1,1);
    }
    for(auto it:g[ctd])if(!vst[it])dfs4(it,1,-1);
    dist[0]--;
    for(auto it:g[ctd])if(!vst[it])dcp(it);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v,n ;
    cin >> n >> K ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dcp(1);
    cout << ans*1ll*K*(K+1)/2%md ;
}
