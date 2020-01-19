#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N)+1,MAX=2e9 ;
vector<int> g[N];
multiset<int> mt[N];
int sub[N],par[N],depth[N];
int dist[N][LOG],clr[N];
bool visited[N];
int fsub(int u)
{
    sub[u]=1;
    visited[u]++;
    for(auto it:g[u])if(!visited[it])sub[u]+=fsub(it);
    visited[u]=0;
    return sub[u];
}
int findcent(int u,int v,int sz)
{
    for(auto it:g[u])if(!visited[it]&&it!=v&&sub[it]>sz/2)
        return findcent(it,u,sz);
    return u ;
}
void getdist(int u,int ctd,int cst)
{
    visited[u]++;
    dist[u][depth[u]-depth[ctd]]=cst;
    for(auto it:g[u])if(!visited[it])getdist(it,ctd,cst+1);
    visited[u]=0;
}
void decompose(int u,int v)
{
    int sz = fsub(u),ctd=findcent(u,v,sz);
    par[ctd]=v,visited[ctd]++,depth[ctd]=depth[v]+1;
    for(auto it:g[ctd])if(!visited[it])decompose(it,ctd);
    visited[ctd]=0;
    getdist(ctd,ctd,0);
}
void E(multiset<int> &a,int val)
{
    a.erase(a.find(val));
}
void color(int u)
{
    int x=u,i=0 ;
    if(clr[u]==0)for(;x;x=par[x],i++)mt[x].insert(dist[u][i]);
    else for(;x;x=par[x],i++)E(mt[x],dist[u][i]);
    clr[u]^=1;
}
int qans(int u)
{
    int mn = MAX,x=u,i=0 ;
    for(;x;x=par[x],i++)mn=min(mn,dist[u][i]+*mt[x].begin());
    return mn<MAX?mn:-1;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m,u,v,x ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)mt[i].insert(MAX);
    decompose(1,0);
    cin >> m ;
    while(m--)
    {
        cin >> u >> v ;
        if(!u)color(v);
        else cout << qans(v) << '\n' ;
    }
}
