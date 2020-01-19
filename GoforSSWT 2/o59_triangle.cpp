#include<bits/stdc++.h>
using namespace std ;
const int N = 109,MOD=1e9+7;
int dp[N][N];
main()
{
    int n,k,i,j,d;
    scanf("%d %d",&n,&k);
    dp[1][2]=1;
    dp[2][1]=1;
    for(j=3;j<=n;j++)
    {
        dp[1][j]=(dp[1][j-1]+(min(j-1,k)))%MOD;
        dp[j][1]=dp[1][j];
    }
    for(i=2;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD;
            for(d=2;d<=i&&d-1<=k;d++)
            {
                dp[i][j]=(dp[i][j]+dp[i-d][j-1]+1)%MOD;
            }
            for(d=2;d<=j&&d-1<=k;d++)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-d]+1)%MOD;
            }
            dp[j][i]=dp[i][j];
        }
    }
    printf("%d",dp[n][n]);
}
