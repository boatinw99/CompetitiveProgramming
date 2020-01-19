#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5e4+9 ,LOG = log2(N)+1 ;
vector<int> g[N];
int dist[N][LOG],clr[N],sub[N],rnk[N],par[N];
int sz[N][2],sum[N][2],pre[N][2];
bool vst[N];
void dfs0(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])if(!vst[it])dfs0(it),sub[u]+=sub[it];
    vst[u]=0;
}
int dfs1(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&!vst[it]&&sub[it]>sz/2)
        return dfs1(it,u,sz);
    return u ;
}
void dfs2(int u,int ctd,int cst)
{
    dist[u][rnk[u]-rnk[ctd]]=cst;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs2(it,ctd,cst+1);
    vst[u]=0;
}
void dcp(int u,int v,int depth)
{
    dfs0(u);
    int ctd = dfs1(u,u,sub[u]);
    par[ctd]=v ;
    rnk[ctd]=depth;
    vst[ctd]++;
    for(auto it:g[ctd])if(!vst[it])dcp(it,ctd,depth+1);
    dfs2(ctd,ctd,0);
}
void update(int u,int col,int mul)
{
    int x = u ;
    while(x)
    {
        sz[x][col]+=mul;
        sum[x][col]+=mul*dist[u][rnk[u]-rnk[x]];
        pre[x][col]+=mul*dist[u][rnk[u]-rnk[x]+1];
        x=par[x];
    }
}
ll query(int u)
{
    int col = clr[u], x = u ;
    ll ans = 0 , exsum=0 , exsz = 0;
    while(x)
    {
        ans+=1ll*dist[u][rnk[u]-rnk[x]]*(sz[x][col]-exsz)+sum[x][col]-exsum;
        exsum = pre[x][col];
        exsz = sz[x][col];
        x=par[x];
    }
    return ans ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,u,v,typ ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> clr[i] ;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dcp(1,0,1);
    for(int i=1;i<=n;i++)update(i,clr[i],1);
    while(m--)
    {
        cin >> typ >> u ;
        if(typ==1)
        {
            update(u,clr[u],-1);
            clr[u]^=1;
            update(u,clr[u],1);
        }
        else cout << query(u) << '\n' ;
    }
    return 0 ;
}
