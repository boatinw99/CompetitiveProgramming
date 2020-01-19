#include<bits/stdc++.h>
using namespace std ;
const int N = 10009,LOG=log2(N)+1;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii> G[N];
int up[N][LOG],sum[N][LOG],depth[N];
int tin[N],tout[N],times=0;
void dfs(int u,int v)
{
    up[u][0]=v;
    tin[u]=++times;
    depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        sum[u][i]=sum[u][i-1]+sum[up[u][i-1]][i-1];
    }
    for(auto it:G[u])
    {
        if(it.first!=v)
        {
            sum[it.first][0]=it.second ;
            dfs(it.first,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v];}
pii lca(int u,int v)
{
    int x=0;
    for(int i=LOG-1;i>=0;i--)
        if(!Islca(up[v][i],u))x+=sum[v][i],v=up[v][i];
    return {x+sum[v][0],up[v][0]};
}
int sumlca(int u,int v)
{
    if(u==v)return 0 ;
    if(Islca(u,v))return lca(u,v).fi;
    if(Islca(v,u))return lca(v,u).fi;
    return lca(u,v).fi+lca(v,u).fi;
}
int walk(int u,int x)
{
    for(int i=LOG-1;i>=0;i--)if((1<<i)&x)u=up[u][i];
    return u;
}
int KTH(int u,int v,int k)
{
    if(Islca(v,u))return walk(u,k-1);
    if(Islca(u,v))return walk(v,depth[v]-depth[u]+1-k);
    int LCA=lca(u,v).second;
    if(depth[u]-depth[LCA]+1>=k)return  walk(u,k-1);
    int x=k-depth[u]+depth[LCA]-1;
    return walk(v,depth[v]-depth[LCA]-x);
}
void re()
{
    for(int i=1;i<N;i++)G[i].clear(); times=0;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,i,j,n,wi,u,v,k ;
    string s ;
    cin >> T;
    while(T--)
    {
        re();
        cin >> n ;
        for(i=1;i<n;i++)
        {
            cin >> u >> v >>wi ;
            G[u].emplace_back(v,wi);
            G[v].emplace_back(u,wi);
        }
        dfs(1,1);
        while(cin >> s && s[1]!='O')
        {
            if(s[0]=='D')
            {
                cin >> u >> v ;
                cout << sumlca(u,v) << '\n';
            }
            else
            {
                cin >> u >> v >> k ;
                cout << KTH(u,v,k) << '\n';
            }
        }
    }
}
