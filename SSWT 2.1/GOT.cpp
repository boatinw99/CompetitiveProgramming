#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 , LOG=log2(N)+1;
int up[N][LOG],pos[N],euler[N],out[N],tin[N],tout[N],times=0,p=0 ;
int f[N],n,ans[2*N];
vector<int> g[N],val[N],query[N] ;
pii edge[2*N] ;
void update(int i,int cst)
{
    for(;i<=n;i+=i&-i)f[i]+=cst ;
}
int getval(int i)
{
    int x = 0 ;
    for(;i;i-=i&-i)x+=f[i] ;
    return x ;
}
void dfs(int u,int v)
{
    up[u][0]=v;
    pos[u]=++p,euler[p]=u ;
    tin[u]=++times;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it!=v)dfs(it,u);
    out[u]=p;
    tout[u]=++times ;
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
int findans(int u,int v)
{
    int lca=findlca(u,v) ;
    int tmp=getval(pos[u])+getval(pos[v])-getval(pos[lca]);
    if(lca>1)tmp-=getval(pos[up[lca][0]]);
    return tmp ;
}
void del()
{
    times=0,p=0;
    for(int i=0;i<N;i++)
        g[i].clear(),val[i].clear(),query[i].clear(),ans[i]=0;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v,cst ;
    while(cin >> n >> m)
    {
        del();
    for(i=1;i<=n;i++)
    {
        cin >> cst ;
        val[cst].push_back(i);
    }
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> cst ;
        edge[i]={u,v};
        query[cst].push_back(i);
    }
    for(i=0;i<=n;i++)
    {
        if(query[i].empty()||val[i].empty())continue ;
        for(auto it:val[i])update(pos[it],1),update(out[it]+1,-1);
        for(auto it:query[i])ans[it]=findans(edge[it].fi,edge[it].se);
        for(auto it:val[i])update(pos[it],-1),update(out[it]+1,1);
    }
    for(i=1;i<=m;i++)
    {
        if(ans[i]>0)cout << "Find" << '\n' ;
        else cout << "NotFind" << '\n' ;
    }
    }

}
