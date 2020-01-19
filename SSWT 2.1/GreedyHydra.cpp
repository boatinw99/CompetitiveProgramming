#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 309,K=309,MAX=1e9+7;
vector<pii> g[N];
int n,m,k,dp[N][2][K];
int tmp[2][N][K],row=1;
void update(int v,int u,int cst)
{
    ///tmp[0][v][k]; -> [0] = bigboss
    ///dp[u][][j];
    for(int j=0;j<=k;j++)
    {
        int tmp1 = min(dp[u][0][j]+cst,dp[u][1][j]);
        for(int x=0;x+j<=k;x++)
        {
            tmp[0][row][x+j]=min(tmp[0][row][x+j],tmp1+tmp[0][row-1][x]);
        }
    }
    ///tmp[1][v][k] ; -> non big boss
    for(int j=0;j<=k;j++)
    {
        int tmp1 ;
        if(m==2)tmp1=min(dp[u][1][j]+cst,dp[u][0][j]);
        else tmp1=min(dp[u][1][j],dp[u][0][j]);
        for(int x=0;x+j<=k;x++)
        {
            tmp[1][row][x+j]=min(tmp[1][row][x+j],tmp1+tmp[1][row-1][x]);
        }
    }
}
void dfs(int u,int v)
{
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dfs(it.fi,u);
        }
    }
    row=1;
    tmp[0][0][1]=0;
    tmp[1][0][0]=0;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            update(u,it.fi,it.se);
            row++;
        }
    }
    //if(u<2)return ;
   // printf("aa %d | %d %d\n",u,tmp[0][row-1][3],tmp[1][row-1][2]);
    for(int j=0;j<=k;j++)
    {
        dp[u][0][j]=tmp[0][row-1][j];
        dp[u][1][j]=tmp[1][row-1][j];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=k;j++)
        {
            tmp[0][i][j]=tmp[1][i][j]=MAX ;
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v,x ;
    cin >> n >> m >> k ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    if(k+m>n)
    {
        cout << -1 ;
        return 0 ;
    }
    for(i=0;i<N;i++)for(j=0;j<K;j++)
    dp[i][0][j]=dp[i][1][j]=tmp[0][i][j]=tmp[1][i][j]=MAX ;
    dfs(1,0);
    cout << dp[1][0][k];
}
