#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N)+1;
vector<int> g[N];
int up[N][LOG],br[N][LOG],depth[N];
int low[N],dist[N];
int tin[N],tout[N],times=0,t=0;
void dfs(int u,int v)
{
    dist[u]=low[u]=++t; depth[u]=depth[v]+1;
    up[u][0]=v;tin[u]=++times ;
    for(auto it:g[u])
    {
        if(!dist[it])
        {
            dfs(it,u);
            low[u]=min(low[u],low[it]);
            if(dist[u]<low[it])br[it][0]=1;
        }
        else if(it!=v)low[u]=min(low[u],dist[it]);
    }
    tout[u]=++times ;
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v]; }
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int findbridge(int u,int cnt)
{
    int sum=0;
    cnt=max(cnt,0);
    for(int i=0;i<LOG;i++)if((1<<i)&cnt)sum+=br[u][i],u=up[u][i];
    return sum ;
}
int ans(int a,int b,int u,int v)
{
    int lca1,lca2,x,y ;
    if(depth[a]>depth[b])swap(a,b); if(depth[u]>depth[v])swap(u,v);
    lca1=findlca(a,v),lca2=findlca(b,v);
    if(depth[lca1]>depth[lca2])swap(lca1,lca2);
     ///u->x + y->v
    if(Islca(u,lca1))x=lca1,y=lca2 ;
    else if(Islca(u,lca2))x=u,y=lca2;
    else x=v,y=v;
    //printf("aa %d %d\n",x,y);
        return findbridge(x,depth[x]-depth[u])+
            findbridge(v,depth[v]-depth[y]);
}
int qans(int a,int b,int u,int v)
{
    int lca=findlca(u,v) ;
    return ans(a,b,lca,u)+ans(a,b,lca,v);
    /// lcauv u + lvauv v
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,T,i,j,u,v,x,y ;
    cin >> n >> m >> T ;
    while(m--)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1);
    for(j=1;j<LOG;j++)for(i=1;i<=n;i++){
        up[i][j]=up[up[i][j-1]][j-1];
        br[i][j]=br[i][j-1]+br[up[i][j-1]][j-1];
    }
    while(T--)
    {
        cin >> x >> y >> u >> v ;
        cout << qans(x,y,u,v) << '\n' ;
    }
}
