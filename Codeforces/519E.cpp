#include<bits/stdc++.h>
using namespace std ;
const int N=1e5+9,LOG = log2(N);
int up[N][LOG+1],tin[N],tout[N],sub[N],depth[N];
vector<int> G[N];
int times=0,n;
void dfs(int u,int v,int cnt)
{
    tin[u]=++times;
    sub[u]++;
    depth[u]=cnt ;
    up[u][0]=v;
    for(int i=1;i<=LOG;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:G[u])
    {
        if(it!=v)dfs(it,u,cnt+1),sub[u]+=sub[it];
    }
    tout[u]=++times ;
}
bool Islca(int u,int v)
{
    return tin[u]<tin[v]&&tout[u]>tin[v];
}
int findlca(int u,int v)
{
    int LCA=0,bits;
    if(Islca(u,v))LCA=u;
    if(Islca(v,u))swap(u,v),LCA=u ;
    if(LCA==u)
    {
        if((depth[v]-depth[u])&1)return 0 ;
        bits=depth[v]-depth[u] >>1;
        ///v binarylifting = bits
        bits-- ;
        for(int i=0;i<=LOG;i++)
        {
            if((1<<i)&bits)
            {
                v=up[v][i];
            }
        }
        return sub[up[v][0]]-sub[v];
    }
    LCA = u ;
    for(int i=LOG;i>=0;i--)
    {
        if(!Islca(up[LCA][i],v))
        {
            LCA=up[LCA][i];
        }
    }
    LCA = up[LCA][0];
    if(depth[u]>=depth[v])swap(u,v);
    if(depth[u]==depth[v])
    {
        bits=depth[u]-depth[LCA] ;
        bits -- ;
        for(int i=0;i<=LOG;i++)
        {
            if((1<<i)&bits)u=up[u][i],v=up[v][i];
        }
        return n-sub[u]-sub[v];
    }
    else
    {
        if((depth[v]+depth[u]-2*depth[LCA])&1)return 0 ;
        bits=depth[v]+depth[u]-2*depth[LCA] >> 1 ;
        bits--;
        for(int i=0;i<=LOG;i++)
        {
            if((1<<i)&bits)v=up[v][i];
        }
        return sub[up[v][0]]-sub[v];
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,T,u,v  ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1,1,0);
    cin >> T ;
    while(T--)
    {
        cin >> u >> v ;
        if(u==v)cout << n << '\n';
        else cout << findlca(u,v) << '\n' ;
    }
}
