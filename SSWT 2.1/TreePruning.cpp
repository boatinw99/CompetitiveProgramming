#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9,K=209;
const ll MIN = -1e16 ;
vector<int> g[N];
int sub[N],a[N],pos[N],f[N],p=1;
ll dp[K][N];
void dfs(int u,int v)
{
    sub[u]=1;
    pos[u]=p;
    f[p++]=u;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs(it,u);
            sub[u]+=sub[it];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j,u,v ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,0);
    for(j=0;j<=n+1;j++)
    {
        for(i=0;i<=k;i++)dp[i][j]=MIN ;
    }
    dp[0][0]=0 ;
    for(j=1;j<=n;j++)
    {
        for(i=0;i<=k;i++)dp[i][j]=max(dp[i][j],dp[i][j-1]);
        for(i=0;i<k;i++)
        {
            dp[i+1][j+sub[f[j]]]=max(dp[i+1][j+sub[f[j]]],dp[i][j]);
        }
        for(i=0;i<=k;i++)dp[i][j]+=a[f[j]];
    }/*
    cout << '\n' ;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=n;j++)
        {
            cout << dp[i][j] << " " ;
        }
        cout << '\n' ;
    }*/
    ll tmp = 0 ;
    for(i=0;i<=k;i++)
    {
        tmp=max(tmp,dp[i][n]);
        tmp=max(tmp,dp[i][n+1]);
    }
    cout << tmp ;
}
