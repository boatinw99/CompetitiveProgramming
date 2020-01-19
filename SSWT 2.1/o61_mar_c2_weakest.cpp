#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 , LOG = log2(N)+1;
int up[N][LOG],mn[N][LOG],tin[N],tout[N],depth[N],times=0;
vector<pii> g[N];
void dfs(int u)
{
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        mn[u][i]=min(mn[u][i-1],mn[up[u][i-1]][i-1]);
    }
    tin[u]=++times ;
    for(auto it:g[u])
    {
        depth[it.fi]=depth[u]+1;
        mn[it.fi][0]=it.se;
        dfs(it.fi);
    }
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
int blift(int u,int cst)
{
    int ret=10000009 ;
    for(int i=0;i<LOG;i++)
    {
        if((1<<i)&cst)
        {
            ret=min(ret,mn[u][i]);
            u=up[u][i];
        }
    }
    return ret ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,q,k,a1,a2 ;
    cin >> n  ;
    for(i=2;i<=n;i++)
    {
        cin >> u >> v ;
        u++;
        up[i][0]=u;
        g[u].emplace_back(i,v);
    }
    tout[0]=1e9 ;
    depth[1]=1;
    dfs(1);
    cin >> q >> k >> m >> a1 >> a2 ;
    while(q--)
    {
        a1++;a2++;
        int lca=findlca(a1,a2);
        int ans=min(blift(a1,depth[a1]-depth[lca]),blift(a2,depth[a2]-depth[lca]));
        if(a1==a2)ans=0;
        cout << ans << '\n' ;
        a1--;a2--;
        int tmp = ((a2*k*1ll+ans)%m)%n ;
        a1=a2;
        a2=tmp ;
    }
}
