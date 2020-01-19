#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ,inf = 1e9+7 , M = 102;
vector<pii> g[N];
vector<pair<int,pii> > par[N]; ///parent ,times,cst ;
vector<int> town ;
int pos[N],n,p=0,times=1;
int dist[M][M];
/// comp -> in chain , hd -> head chain ;
bool vst[N];
void dfs0(int u,int cst,int head)
{
    par[u].push_back({head,{times,cst}});
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it.fi]&&g[it.fi].size()==2)dfs0(it.fi,cst+it.se,head);
        else if(g[it.fi].size()>2)
        {
            cst+=it.se ;
            dist[pos[head]][pos[it.fi]]=min(cst,dist[pos[head]][pos[it.fi]]) ;
            cst-=it.se ;
        }
    }
    vst[u]=0 ;
}
void pre()
{
    int i,j,k ;
    for(i=0;i<M;i++)for(j=0;j<M;j++)dist[i][j]=inf ;
    for(i=0;i<M;i++)dist[i][i]=0 ;
    for(auto it:town)
    {
        for(auto it1:g[it])
        {
            times++;
            dfs0(it1.fi,it1.se,it);
        }
    }
    for(i=0;i<M;i++)for(j=0;j<M;j++)
    {
        dist[i][j]=min(dist[i][j],dist[j][i]);
        dist[j][i]=min(dist[i][j],dist[j][i]);
    }
    for(k=0;k<p;k++)for(i=0;i<p;i++)for(j=0;j<p;j++)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

}
int qans(int u,int v)
{
    int ans = 0 ,mn = inf ;
    if(u==v)return 0 ;
    if(g[u].size()==1)
    {
        ans+=g[u][0].se ;
        u=g[u][0].fi;
    }
    if(g[v].size()==1)
    {
        ans+=g[v][0].se ;
        v=g[v][0].fi ;
    }
    if(par[u][0].fi==par[v][0].fi&&par[u][0].se.fi==par[v][0].se.fi)
        mn=min(mn,abs(par[u][0].se.se-par[v][0].se.se));
    for(auto it:par[u])
    {
        for(auto it1:par[v])
        {
            mn=min(mn,dist[pos[it.fi]][pos[it1.fi]]+it.se.se+it1.se.se);
        }
    }
    return mn+ans ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,q,i,j,u,v,x ;
    cin >> n >> m >> q ;
    while(m--)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    g[1].emplace_back(N-2,inf);
    g[1].emplace_back(N-2,inf);
    for(i=1;i<=n;i++)
    {
        if(g[i].size()>2)
        {
            town.push_back(i);
            pos[i]=p++;
            par[i].push_back({i,{-1,0}});
        }
    }
    pre();
    while(q--)
    {
        cin >> u >> v ;
        cout << qans(u,v) << '\n' ;
    }
}
