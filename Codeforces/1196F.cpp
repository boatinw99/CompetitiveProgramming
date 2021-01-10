#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 2e5+9 ; 
int n,m,k ;
vector<pair<ll,pii>> edge ; 
vector<pii> g[N] ;
vector<ll> kth ; 
vector<int> Vnode ; 
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq ;
ll dist[N];
void dijk(int node)
{
    dist[node]=0 ;
    for(pq.push({0,node});!pq.empty();)
    {
        pair<ll,int> P=pq.top();  
        pq.pop();
        if(dist[P.se]!=P.fi)
        {
            continue ;
        }
        if(P.fi>0)
        {
            kth.emplace_back(P.fi);
        }
        for(auto it:g[P.se])
        {
            if(P.fi+it.se<dist[it.fi])
            {
                dist[it.fi]=P.fi+it.se ;
                pq.push({dist[it.fi],it.fi});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m >> k ;
    for(int i=1,u,v,wi ;i<=m;i++)
    {
        cin >> u >> v >> wi ;
        edge.push_back({wi,{u,v}});
    }
    sort(edge.begin(),edge.end());
    edge.resize(min(m,k));
    for(auto it:edge)
    {
        g[it.se.fi].emplace_back(it.se.se,it.fi);
        g[it.se.se].emplace_back(it.se.fi,it.fi);
        Vnode.push_back(it.se.fi);
        Vnode.push_back(it.se.se);
    }
    sort(Vnode.begin(),Vnode.end());
    Vnode.resize(unique(Vnode.begin(),Vnode.end())-Vnode.begin());
    for(auto it:Vnode)
    {
        for(auto node:Vnode)dist[node]=INF ;
        dijk(it);
    }
    sort(kth.begin(),kth.end());
    /*for(auto it:Vnode)
    {
        printf("%lld ",it);
    }
    printf("\n");
    */
    cout << kth[2*k-1] << '\n' ;
    return 0 ;
}