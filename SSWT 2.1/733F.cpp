#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ,LOG=log2(N)+1 ;
int up[N][LOG],tin[N],tout[N],times=0,mn=INT_MAX,depth[N],S;
int edp=0,ep=0 ;
///edge dont print , edge print ;
ll sum = 0,ans ;
bool visited[N];
pii edge[N],mx[N][LOG];
///weight,cst ;
priority_queue<pair<pii,pii> > pq ;
vector<pii> g[N],tree[N],ntree[N];
void mst()
{
    for(pq.push({{0,0},{1,1}});!pq.empty();)
    {
        int cst = -pq.top().fi.fi,i=pq.top().fi.se;
        int u=pq.top().se.fi,v=pq.top().se.se;
        pq.pop();
        if(!visited[u]++)
        {
            tree[u].emplace_back(v,i);
            tree[v].emplace_back(u,i);
            for(auto it:g[u])if(!visited[it.fi])
                pq.push({{-edge[it.se].fi,it.se},{it.fi,u}});
        }
        else ntree[u].emplace_back(v,i);
    }
}
void dfs(int u,int v)
{
    tin[u]=++times ;
    up[u][0]=v,depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        if(mx[u][i-1]>=mx[up[u][i-1]][i-1])mx[u][i]=mx[u][i-1];
        else mx[u][i]=mx[up[u][i-1]][i-1];
    }
    for(auto it:tree[u])
    {
        if(it.fi!=v)
        {
            mx[it.fi][0]={edge[it.se].fi,it.se};
            dfs(it.fi,u);
            sum+=edge[it.se].fi ;
            if(edge[it.se].se<mn)
            {
                mn=edge[it.se].se ;
                ep=it.se ;
            }
        }
    }
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u;
    if(Islca(v,u))return v;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
pii findmax(int u,int cst)
{
    pii x={0,0};
    for(int i=0;i<LOG;i++)
    {
        if((1<<i)&cst)
        {
            if(mx[u][i].fi>x.fi)x=mx[u][i];
            u=up[u][i];
        }
    }
    return x ;
}
void qans(int u,int v,int i)
{
    if(edge[i].se>=mn)return ;
    int lca=findlca(u,v);
    pii tmp1=findmax(u,depth[u]-depth[lca]);
    pii tmp2=findmax(v,depth[v]-depth[lca]);
    if(tmp1.fi<tmp2.fi)tmp1=tmp2 ;
    if(sum-tmp1.fi+edge[i].fi-S/edge[i].se<ans)
    {
        ans=sum-tmp1.fi+edge[i].fi-S/edge[i].se;
        edp = tmp1.se ;
        ep = i ;
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)cin >> edge[i].fi ;
    for(i=1;i<=m;i++)cin >> edge[i].se ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    cin >> S ;
    mst(),dfs(1,1);
    ans = sum - S/mn;
    for(i=1;i<=n;i++)for(auto it:ntree[i])qans(i,it.fi,it.se);
    cout << ans << '\n' ;
    memset(visited,0,sizeof visited);
    visited[0]++ ;
    for(i=1;i<=n;i++)
    {
        for(auto it:tree[i])if(it.se!=edp&&it.se!=ep&&!visited[it.se]++)
            cout << it.se << " " << edge[it.se].fi << '\n' ;
    }
    cout << ep << " " << edge[ep].fi-S/edge[ep].se;
}
