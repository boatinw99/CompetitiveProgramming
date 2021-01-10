#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef double Ld ;
const int N = 1e5+9,LOG=log2(N)+1;
vector<int> G[N];
int up[N][LOG];
int tin[N],tout[N],sub[N],hi[N],subup[N];
ll depth[N],dup[N] ;
int times=0;
void dfs(int u,int v)
{
    up[u][0]=v;
    for(int i=1;i<LOG;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    tin[u]=++times;
    sub[u]=1 ;
    hi[u]=hi[v]+1;
    for(auto it:G[u])
    {
        if(it!=v)
        {
            dfs(it,u);
            sub[u]+=sub[it];
            depth[u]+=depth[it]+sub[it];
        }
    }
    tout[u]=++times;
}
void dfs1(int u,int v)
{
    subup[u]=subup[v]+sub[v]-sub[u];
    dup[u]=depth[v]-depth[u]-sub[u]+sub[v]-sub[u]+dup[v]+subup[v];
    dup[1]=0;
    for(auto it:G[u])
    {
        if(it!=v)dfs1(it,u);
    }
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v]; }
pair<int,int> lca(int u,int v)
{
    int x=0 ;
    for(int i=LOG-1;i>=0;i--)
        if(!Islca(up[v][i],u))v=up[v][i],x+=(1<<i);
    return {x+1,v} ;
}
Ld findlca(int u,int v)
{
    pair<int,int> D;
    int z,LCA=0,subu ;
    Ld path,x,du,y=1.0000000 ;
    if(Islca(u,v))LCA=u ;
    if(Islca(v,u))LCA=v,swap(u,v);
    if(LCA==u)
    {
        D=lca(u,v); path=D.first+1; z = D.second ;
        du=dup[u]+depth[u]-depth[z]-sub[z];
        subu=subup[u]+sub[u]-sub[z];
        x=y*du/subu+y*depth[v]/sub[v];
        return path+x;
    }
    else
    {
        path=lca(u,v).first+lca(v,u).first+1;
        x=y*depth[u]/sub[u]+y*depth[v]/sub[v];
        return path+x;
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T,u,v,i,j ;
    cin >> n >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    hi[1]=-1;
    dfs(1,1);
    dfs1(1,1);
    while(T--)
    {
        cin >> u >> v ;
        printf("%.8f\n",findlca(u,v));
    }
}
