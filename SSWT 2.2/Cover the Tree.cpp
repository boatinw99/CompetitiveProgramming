#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<int> g[N];
vector<pii> ans ;
priority_queue<pii> pq;
int dist[N];
vector<int> leaf[N] ;
void dfs0(int u,int v)
{
    if(g[u].size()==1)dist[u]++;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            dist[u]+=dist[it];
        }
    }
}
int dfs1(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&dist[it]>sz/2)return dfs1(it,u,sz);
    return u ;
}
void dfs2(int u,int v,int par)
{
    if(g[u].size()==1)leaf[par].emplace_back(u);
    for(auto it:g[u])if(it!=v)dfs2(it,u,par);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,u,v ;
    cin >> n ;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    int root = dfs1(1,1,dist[1]);
    for(auto it:g[root])
    {
        dfs2(it,root,it);
        pq.push({leaf[it].size(),it});
    }
    while(pq.size()>1)
    {
        pii x = pq.top();
        pq.pop();
        pii y = pq.top();
        pq.pop();
        if(x.fi>1)pq.push({x.fi-1,x.se});
        if(y.fi>1)pq.push({y.fi-1,y.se});
        ans.emplace_back(leaf[x.se].back(),leaf[y.se].back());
        leaf[x.se].pop_back();
        leaf[y.se].pop_back();
    }
    if(!pq.empty())ans.emplace_back(leaf[pq.top().se].back(),root);
    cout << ans.size() << '\n' ;
    for(auto it:ans)cout << it.fi << " " << it.se << '\n' ;
    return 0 ;
}
