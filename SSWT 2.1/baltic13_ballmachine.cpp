#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ,LOG=log2(N)+1;
vector<int> pre,g[N];
int mn[N],tin[N],tout[N],times=0,p=0,up[N][LOG],depth[N],pos[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;///rnk,node
bool est[N];
bool cmp(int u,int v)
{
    return mn[u]<mn[v];
}
void dfs0(int u)
{
    mn[u]=u;
    for(auto it:g[u])
    {
        dfs0(it);
        mn[u]=min(mn[u],mn[it]);
    }
}
void dfs1(int u)
{
    tin[u]=++times;
    depth[u]=depth[up[u][0]]+1;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])
    {
        dfs1(it);
    }
    pre.push_back(u);
    tout[u]=++times;
}
int blift(int u)
{
    for(int i=LOG-1;i>=0;i--)if(est[up[u][i]])u=up[u][i];
    return u ;
}
int update(int k)
{
    int x ;
    while(k--)
    {
        est[pq.top().se]++;
        x=pq.top().se;
        pq.pop();
    }
    return x ;
}
int qans(int u)
{
    int v = blift(u);
    est[v]=0;
    pq.push({pos[v],pre[pos[v]]});
    return depth[u]-depth[v] ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,u,v,i,j,t ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> u  ;
        up[i][0]=u ;
        g[u].emplace_back(i);
    }
    dfs0(0);
    for(i=1;i<=n;i++)sort(g[i].begin(),g[i].end(),cmp);
    dfs1(0);
    for(i=0;i<n;i++)
    {
        pq.push({i,pre[i]});
        pos[pre[i]]=i;
    }
    while(m--)
    {
        cin >> t >> u ;
        if(t==1)
        {
            cout << update(u);
        }
        else
        {
            cout << qans(u);
        }
        cout << '\n';
    }
}
