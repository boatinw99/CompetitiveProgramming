#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5e3+9 ;
const ll MAX = 1e16 ;
ll dp[2][N][N];
int a[N],b[N],sub[N],n ; ///0 -> use , 1 non-use
vector<int> g[N];
void dfs(int u)
{
    sub[u]=1;
    for(auto it:g[u])dfs(it),sub[u]+=sub[it];
    dp[1][0][u]=0 ;
    dp[0][1][u]=a[u]-b[u];
    dp[1][1][u]=a[u];
    int sz=1;
    for(auto it:g[u])
    {
        for(int j=sz;j>=0;j--)for(int i=sub[it];i>=1;i--)
        {
            dp[1][j+i][u]=min(dp[1][j+i][u],dp[1][j][u]+dp[1][i][it]);
            dp[0][j+i][u]=min(dp[0][j+i][u],dp[0][j][u]+
                                min(dp[0][i][it],dp[1][i][it]));
        }
        sz+=sub[it];
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,u,v ;
    cin >> n >> k ;
    cin >> a[1] >> b[1];
    for(i=2;i<=n;i++)
    {
        cin >> a[i] >> b[i] >> u ;
        g[u].emplace_back(i);
    }
    for(i=0;i<N;i++)for(j=0;j<N;j++)dp[0][i][j]=dp[1][i][j]=MAX ;
    dfs(1);
    int mx = 0 ;
    for(i=0;i<=n;i++)
    {
        if(dp[0][i][1]<=k||dp[1][i][1]<=k)mx=i ;
    }
    cout << mx ;
}
