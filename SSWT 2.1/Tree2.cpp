#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e4+9,LOG=log2(N)+1;
vector<int> g[N];
int up[N][LOG],depth[N],tin[N],tout[N],times=0 ;
pii mxd[N],mxu[N];///from down & up
void dfs1(int u,int v)
{
    tin[u]=++times ;
    depth[u]=depth[v]+1;
    up[u][0]=v;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs1(it,u);
            if(depth[mxd[it].fi]>depth[mxd[u].fi])
                mxd[u].se=mxd[u].fi,mxd[u].fi=mxd[it].fi;
            else if(depth[mxd[it].fi]>depth[mxd[u].se])
                mxd[u].se=mxd[it].fi;
        }
    }
    tout[u]=++times;
    if(depth[u]>depth[mxd[u].fi])mxd[u].fi=u;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
void dfs2(int u,int p,int cst)
{
    mxu[u]={p,cst};
    for(auto it:g[u])
    {
        if(it!=up[u][0])
        {
            if(mxd[u].fi==mxd[it].fi)
            {
                int tmp = depth[mxd[u].se]-2*depth[u];
                if(tmp>cst)dfs2(it,mxd[u].se,tmp);
                else dfs2(it,p,cst);
            }
            else
            {
                int tmp=depth[mxd[u].fi]-2*depth[u];
                if(tmp>cst)dfs2(it,mxd[u].fi,tmp);
                else dfs2(it,p,cst);
            }
        }
    }
}
int blift(int u,int cst)
{
    for(int i=0;i<LOG;i++)if((1<<i)&cst)u=up[u][i];
    return u ;
}
int qans(int u,int cst)
{
    if(depth[u]>=cst)return blift(u,cst);
    if(depth[mxd[u].fi]-depth[u]>=cst)
        return blift(mxd[u].fi,depth[mxd[u].fi]-depth[u]-cst);
    if(mxu[u].se>=cst-depth[u])
    {
        int tmp = mxu[u].fi,lca=findlca(u,tmp);
        int x = cst-depth[u]+depth[lca];
        return blift(tmp,depth[tmp]-depth[lca]-x);
    }
    return 0 ;
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,T,u,v,d ;
    cin >> n >> T ;
    depth[1]=-1;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(1,1);
    dfs2(1,0,-1);
    while(T--)
    {
        cin >> u >> d ;
        cout << qans(u,d) << '\n';
    }
}
