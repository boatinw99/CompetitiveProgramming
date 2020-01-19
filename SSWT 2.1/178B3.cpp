#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N)+1;
typedef pair<int,int> pii;
int up[N][LOG],br[N][LOG];
int tin[N],tout[N];
int dist[N],low[N];
bool b[N];
vector<pii> G[N];
int times=0 ;
void findbridge(int u,int v)
{
    vector<pii>::iterator it ;
    dist[u]=low[u]=++times;
    for(it=G[u].begin();it!=G[u].end();it++)
    {
        if(!dist[it->first])
        {
            findbridge(it->first,u);
            low[u]=min(low[u],low[it->first]);
            if(dist[u]<low[it->first])it->second=1;
        }
        else if(it->first!=v)
        {
            low[u]=min(low[u],dist[it->first]);
        }
    }
}
void dfs(int u,int v)
{
    up[u][0]=v;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        br[u][i]=br[u][i-1]+br[up[u][i-1]][i-1];
    }
    for(auto it:G[u])
    {
        if(!b[it.first]++)
        {
            br[it.first][0]=it.second;
            dfs(it.first,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v];}
int lca(int u,int v)
{
    int sum=0;
    for(int i=LOG-1;i>=0;i--)
        if(!Islca(up[v][i],u))sum+=br[v][i],v=up[v][i];
    return sum+br[v][0] ;
}
int findlca(int u,int v)
{
    if(Islca(u,v))return lca(u,v);
    if(Islca(v,u))return lca(v,u);
    return lca(u,v)+lca(v,u);
}
main()
{
    /// 0 is nonbridge , 1 is bridge
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,i,j,u,v,T ;
    cin >> n >> m ;
    while(m--)
    {
        cin >> u >> v ;
        G[u].push_back({v,0});
        G[v].push_back({u,0});
    }
    b[1]++;
    findbridge(1,1);
    times=0;
    dfs(1,1);
    cin >> T ;
    while(T--)
    {
        cin >> u >> v ;
        if(u==v)cout << 0 <<'\n';
        else cout << findlca(u,v) << '\n' ;
    }
}
