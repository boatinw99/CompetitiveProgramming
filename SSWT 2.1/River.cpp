#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 109, K=59;
const ll MAX=1e11+7 ;
vector<pii> g[N];
int a[N],k,n,tin[N],tout[N],times=0;
ll dist[N];
ll dp[N][N][K];
ll tmp[N][N][K];
void dfs1(int u)
{
    tin[u]=++times;
    for(auto it:g[u])
    {
        dist[it.fi]=dist[u]+it.se ;
        dfs1(it.fi);
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
void update(int v,int u,int row)
{
    for(int i=0;i<=n;i++)
    {
        if(Islca(i,v))
        {
            for(int j=0;j<=k;j++)
            {
                for(int r=0;r+j<=k;r++)
                {
                    tmp[i][row][r+j]=min(tmp[i][row][r+j],
                            dp[u][i][j]+tmp[i][row-1][r]);
                }
            }
            for(int r=1;r<=k;r++)
                tmp[i][row][r]=min(tmp[i][row][r],tmp[i][row][r-1]);
        }
    }
}
void dfs2(int u)
{
    int i,j,x,sub=1 ;
    for(auto it:g[u])dfs2(it.fi);
    for(i=0;i<=n;i++)if(Islca(i,u))tmp[i][0][0]=(dist[u]-dist[i])*a[u];
    for(auto it:g[u])
    {
        update(u,it.fi,sub);
        sub++;
    }
    for(i=0;i<=n;i++)
    {
        if(Islca(i,u))
        {
            for(j=0;j<=k;j++)
            {
                dp[u][i][j]=tmp[i][sub-1][j];
            }
        }
    }
    for(j=0;j<k;j++)
    {
        for(i=0;i<=n;i++)
        {
            if(Islca(i,u))
            {
                dp[u][i][j+1]=min(dp[u][i][j+1],dp[u][u][j]);
            }
        }
    }
    for(i=0;i<=n;i++)if(Islca(i,u))for(j=0;j<sub;j++)
        for(x=0;x<=k;x++)tmp[i][j][x]=MAX;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int x,u,v,i,j ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] >> u >> v ;
        g[u].emplace_back(i,v);
    }
    for(i=0;i<N;i++)for(j=0;j<N;j++)for(x=0;x<K;x++)
        tmp[i][j][x]=dp[i][j][x]=MAX;
    dfs1(0),dfs2(0);
    cout << dp[0][0][k];
}
