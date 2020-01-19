#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e4+9,MAX=1e9+7 ;
vector<pii> g[N],rg[N]; /// graph , reverse
priority_queue<pii,vector<pii>,greater<pii>> pq;
int dist[N],rdist[N];
int n,m,s,t,p ;
void re()
{
    for(int i=0;i<N;i++)g[i].clear(),rg[i].clear();
}
void dijkstra()
{
    fill(dist,dist+N,MAX);
    fill(rdist,rdist+N,MAX);
    dist[s]=0 ;
    rdist[t]=0;
    for(pq.push({0,s});!pq.empty();)
    {
        int cst=pq.top().fi,u=pq.top().se;
        pq.pop();
        if(dist[u]!=cst)continue ;
        for(auto it:g[u])
        {
            if(it.se+cst<dist[it.fi])
            {
                dist[it.fi]=it.se+cst ;
                pq.push({it.se+cst,it.fi});
            }
        }
    }
    for(pq.push({0,t});!pq.empty();)
    {
        int cst=pq.top().fi,u=pq.top().se;
        pq.pop();
        if(rdist[u]!=cst)continue ;
        for(auto it:rg[u])
        {
            if(it.se+cst<rdist[it.fi])
            {
                rdist[it.fi]=it.se+cst ;
                pq.push({it.se+cst,it.fi});
            }
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T,i,j,u,v,x ;
    cin >> T ;
    while(T--)
    {
        cin >> n >> m >> s >> t >> p ;
        re();
        while(m--)
        {
            cin >> u >> v >> x ;
            g[u].emplace_back(v,x);
            rg[v].emplace_back(u,x);
        }
        dijkstra();
        int ans=0 ;
        for(i=1;i<=n;i++)
        {
            for(auto it:g[i])
            {
                if(dist[i]+it.se+rdist[it.fi]<=p)
                {
                    ans=max(ans,it.se);
                }
            }
        }
        if(ans==0)cout << -1 << '\n';
        else cout << ans << '\n' ;
    }
}
