#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int > pii ;
#define fi first
#define se second
const int N = 1e5+9 ,  LOG = log2(N)+1 ;
pii md[N];///maxdown
int mu[N];///maxup
vector<int> G[N];
int up[N][LOG],depth[N];
int tin[N],tout[N],times=0;
void re()
{
    for(int i=1;i<N;i++)G[i].clear();
    memset(tin,0,sizeof tin);
    memset(tout,0,sizeof tout);
    memset(mu,0,sizeof mu);
    memset(md,0,sizeof md);
    memset(depth,0,sizeof depth);
    memset(up,0,sizeof up);
    times=0;
}
void dfs(int u,int v)
{
    tin[u]=++times;
    up[u][0]=v; depth[u]=depth[v]+1; md[u]={depth[u],0};
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:G[u])if(it!=v){
        dfs(it,u);
        if(md[it].fi>md[u].fi)md[u].se=md[u].fi,md[u].fi=md[it].fi;
        else if(md[it].fi>md[u].se)md[u].se=md[it].fi ;
    }
    tout[u]=++times;
}
void dfs1(int u,int v)
{
    int x;
    for(auto it:G[u])if(it!=v)
    {
        if(md[it].fi==md[u].fi)x=md[u].se ; else x=md[u].fi ;
        mu[it]=max(mu[u]+1,x-depth[u]+1);
        dfs1(it,u);
    }
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v]; }
int findlca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int lift(int u,int val)
{
    for(int i=0;i<LOG;i++)if((1<<i)&val)u=up[u][i];
    return u ;
}
int qans(int u,int v)
{/// T Jerry
    int lca,x,max1=0,dist  ;
    if(Islca(u,v))
    {
        lca=lift(v,depth[v]-depth[u]-1>>1);
        return md[lca].fi-depth[u];
    }
    if(Islca(v,u))
    {
        x=lift(u,depth[u]-depth[v]>>1);   lca=up[x][0];
        /// lca | x
        max1=md[lca].se ;///up
        if(md[x].fi!=md[lca].fi)max1=md[lca].fi;
        return max(max1-2*depth[lca]+depth[u],
                        mu[lca]+depth[u]-depth[lca]);
    }
    lca=findlca(u,v); dist=depth[u]+depth[v]-2*depth[lca]-1>>1;
    if(dist<depth[v]-depth[lca])
        return md[lift(v,dist)].fi-2*depth[lca]+depth[u];
    else
    {
        dist = depth[u]+depth[v]-2*depth[lca]-dist ;
        x=lift(u,dist-1); lca=up[x][0];
        max1=md[lca].se ; if(md[x].fi!=md[lca].fi)max1=md[lca].fi;
        return max(max1-2*depth[lca]+depth[u],
                        mu[lca]+depth[u]-depth[lca]);
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q,T,i,j,n,u,v ;
    cin >> Q ;
    while(Q--)
    {
        re();
        cin >> n >> T;
        for(i=1;i<n;i++)
        {
            cin >> u >> v ;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        dfs(1,1); dfs1(1,1);
        while(T--)
        {
            cin >> u >> v ;
            if(u==v)cout << "0" << '\n';
            else cout << qans(u,v) << '\n' ;
        }
    }
}
