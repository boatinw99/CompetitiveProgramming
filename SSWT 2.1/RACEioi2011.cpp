#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9,K=1e6+9 ;
vector<pii> g[N];
int k,mn=N ;
int sub[N],dist[K];
bool vst[N];
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it.fi!=v&&!vst[it.fi]&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,int cst,int num)
{
    if(cst>k)return ;
    if(cst<=k)mn=min(mn,num+dist[k-cst]);
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs3(it.fi,cst+it.se,num+1);
    vst[u]=0;
}
void dfs4(int u,int cst,int num)
{
    if(cst>k)return ;
    dist[cst]=min(num,dist[cst]);
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs4(it.fi,cst+it.se,num+1);
    vst[u]=0;
}
void dfs5(int u,int cst)
{
    if(cst>k)return ;
    dist[cst]=N;
    vst[u]++;
    for(auto it:g[u])if(!vst[it.fi])dfs5(it.fi,cst+it.se);
    vst[u]=0 ;
}
void decompose(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    dist[0]=0;
    for(auto it:g[ctd])
    {
        if(!vst[it.fi])
        {
            dfs3(it.fi,it.se,1);
            dfs4(it.fi,it.se,1);
        }
    }
    dfs5(ctd,0);
    vst[ctd]++;
    for(auto it:g[ctd])if(!vst[it.fi])decompose(it.fi);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v,x ;
    cin >> n >> k ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    fill(dist,dist+K-1,N);
    decompose(0);
    if(mn<=n)cout << mn ;
    else cout << -1;
}
