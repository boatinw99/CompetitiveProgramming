#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e16 ; 
const int N = 1e3+9 , M = 1e4+9 ; 
int n,m,L,s,t ;
pair<pii,ll> edge[M];
bool marked[M];
pli dist[N];
vector<pii> g[N];
ll dijk()
{
    priority_queue<pli,vector<pli>,greater<pli>> pq ;
    for(int i=0;i<n;i++)dist[i]={INF,i};
    dist[s]={0,0};
    for(pq.push({0,s});!pq.empty();)
    {
        ll cst = pq.top().fi; 
        int u = pq.top().se ;
        pq.pop();
        if(cst!=dist[u].fi)continue ;
        for(auto it:g[u])
        {
            if(cst+edge[it.se].se<dist[it.fi].fi)
            {
                dist[it.fi] = {cst+edge[it.se].se,it.se};
                pq.push({dist[it.fi].fi,it.fi});
            }
        }
    }
    return dist[t].fi ;
}
void trace_back(int u)
{
    int num_edge = dist[u].se ;
    if(marked[num_edge])
    {
        edge[num_edge].se=L-dist[t].fi+1;
        return ;
    }
    int v = edge[num_edge].fi.fi;
    if(v==u)v=edge[num_edge].fi.se; 
    trace_back(v);
}
void pr()
{
    cout << "YES" << '\n' ;
    for(int i=1;i<=m;i++)
    {
        cout << edge[i].fi.fi << " " << edge[i].fi.se << " " << edge[i].se << '\n' ;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m >> L >> s >> t ;
    for(int i=1;i<=m;i++)
    {
        cin >> edge[i].fi.fi >> edge[i].fi.se >> edge[i].se;  
        if(edge[i].se==0)
        {
            marked[i]=1;
        }
        else 
        {
            g[edge[i].fi.fi].emplace_back(edge[i].fi.se,i);
            g[edge[i].fi.se].emplace_back(edge[i].fi.fi,i);
        }
    }
    if(dijk()<L)
    {
        cout << "NO" << '\n' ;
        return 0 ;
    }
    if(dijk()==L)
    {
        for(int i=1;i<=m;i++)if(marked[i])edge[i].se=INF ; 
        pr();
        return 0 ;
    }
    for(int i=1;i<=m;i++)
    {
        if(marked[i])
        {
            edge[i].se=1;
            g[edge[i].fi.fi].emplace_back(edge[i].fi.se,i);
            g[edge[i].fi.se].emplace_back(edge[i].fi.fi,i);;
        }
    }
    if(dijk()>L)
    {
        cout << "NO" << '\n' ;
        return 0 ;
    }
    while(dijk()<L)
    {
        trace_back(t);
    }
    pr();
    return 0 ;
}