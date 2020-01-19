#include<bits/stdc++.h>
using namespace std ;
const int N = 309 ;
int dp[N][N],a[N][N];
main()
{
    int n,m,i,j,k,u,v ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        a[u][v]++;
    }
    for(i=n;i>=1;i--)
    {
        for(j=i;j<=n;j++)
        {
            for(k=i;k<j;k++)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i][j]);
        }
    }
    cout << m-dp[1][n];
}
