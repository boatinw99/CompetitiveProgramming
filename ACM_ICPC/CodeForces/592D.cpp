#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
vector<int> g[N],gt[N];
int depth[N],num_edges = 0 ;
bool clr[N];
int clear_edge(int u,int v)
{
    int isclr = clr[u] ;
    for(auto it:gt[u])
    {
        if(it!=v)
        {
            isclr=max(isclr,clear_edge(it,u));
        }
    }
    if(isclr&&u!=v)
    {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        num_edges++; 
    }
    return isclr; 
}
int diameter(int u,int v,int cst)
{
    int ret = u ;
    depth[u]=cst ; 
    for(auto it:g[u])
    {
        if(it!=v)
        {
            int dfs = diameter(it,u,cst+1);
            if(depth[dfs]>depth[ret])ret = dfs ;
            else if(depth[dfs]==depth[ret])ret=min(ret,dfs);
        }
    }
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ; 
    for(int i=1,u,v;i<n;i++)
    {
        cin >> u >> v ;
        gt[u].emplace_back(v);
        gt[v].emplace_back(u);
    }
    int tele = 0 ;
    for(int i=1,u ;i<=m;i++)
    {
        cin >> u ;
        tele=u ;
        clr[u]++; 
    }
    clear_edge(tele,tele);
    int furthest1 = diameter(tele,tele,0);
    int furthest2 = diameter(furthest1,furthest1,0);
    cout << min(furthest1,furthest2) << '\n' ;
    cout << 2*num_edges-depth[furthest2] << '\n' ;
    return 0 ;
}