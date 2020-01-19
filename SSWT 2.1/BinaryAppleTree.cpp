#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 109 , K=109 , MIN =-1e9;
vector<pii> g[N];
int dp[N][K],tmp[N][K];
///[0] -> non-cut || [1] -> cut
int n,k,row=0 ;
void update(int v,int u,int cst)
{
    /// update -> tmp[0][row][k] is non-cut
    //tmp[row][row]=
    for(int j=0;j<=k;j++)tmp[row][j]=tmp[row-1][j];
    for(int j=0;j<=k;j++)
    {
        //printf("aaa %d | %d %d %d\n",u,dp[u][0]+cst,dp[u][1]+cst,dp[u][2]+cst);
        for(int x=0;x+j+1<=k;x++)
        {
            tmp[row][x+j+1]=max(tmp[row][x+j+1],tmp[row-1][j]+dp[u][x]+cst);
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
    row=1 ;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            update(u,it.fi,it.se);
            row++;
        }
    }
    for(int j=0;j<=k;j++)
    {
        dp[u][j]=tmp[row-1][j];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=k;j++)
        {
            tmp[i][j]=0;
        }
    }
    //printf("aaa %d | %d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2]);
}
main()
{
    int i,j,u,v,x ;
    cin >> n >> k ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    dfs(1,0);
    cout << dp[1][k];
}
