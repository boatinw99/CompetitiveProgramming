#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 50009 ,inf = 2e9, LOG = log2(N)+1;
vector<pii> g[N];
priority_queue<pii,vector<pii>, greater<pii> > pq ;
int dist[N],S[N],T[N],tin[N],tout[N],up[N][LOG],times=0;
void solve(int u,int v)
{
    pq.push({0,u});
    fill(dist,dist+N-1,inf);
    dist[u]=0 ;
    while(!pq.empty())
    {
        int cst = pq.top().fi ;
        int u = pq.top().se ;
        pq.pop();
        if(dist[u]!=cst)continue ;
        if(u==v)
        {
            cout << cst << '\n' ;
            break;
        }
        for(auto it:g[u])
        {
            if(dist[u]+it.se<dist[it.fi])
            {
                dist[it.fi]=dist[u]+it.se;
                pq.push({dist[it.fi],it.fi});
            }
        }
    }
    while(!pq.empty())pq.pop();
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))
        u=up[u][i];
    }
    return up[u][0];
}
void dfs0(int u,int v)
{
    up[u][0]=v;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    tin[u]=++times;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dist[it.fi]=dist[u]+it.se;
            dfs0(it.fi,u);
        }
    }
    tout[u]=++times;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,s,t,m,q ;
    cin >> n >> s >> t >> m >> q ;
    for(int i=1;i<=m;i++)
    {
        int u,v,x ;
        cin >> u >> v >> x;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    for(int i=1;i<=s;i++)cin >> S[i];
    for(int i=1;i<=t;i++)cin >> T[i];
    if(q==2)
    {
        int u,v ;
        cin >> u >> v ;
        solve(u,v);
        cin >> u >> v;
        solve(u,v);
    }
    else if(m==n-1)
    {
        dfs0(1,1);
        int u,v;
        while(q--)
        {
            cin >> u >> v ;
            cout << dist[u]+dist[v]-2*dist[findlca(u,v)] << '\n' ;
        }
    }
    else
    {

    }
    return 0 ;
}
