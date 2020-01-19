#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
int a[N][N];
int dp[N][N];
main()
{
    int n,m,i,j ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i+3][j+3]);
        }
    }
    int x,y;
    for(i=4;i<=n+4;i++)
    {
        for(j=4;j<=m+4;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            x=max(dp[i-2][j-1],dp[i-1][j-2]);
            y=max(x,dp[i][j-3]);
            dp[i][j]=max(dp[i][j],y+a[i][j-1]+a[i][j]);
            y=max(x,dp[i-3][j]);
            dp[i][j]=max(dp[i][j],y+a[i-1][j]+a[i][j]);
            x=max(dp[i][j-2],dp[i-1][j-1]);
            x=max(x,dp[i-2][j]);
            dp[i][j]=max(dp[i][j],x+a[i][j]);
        }
    }
    printf("%d",dp[n+4][m+4]);
}
