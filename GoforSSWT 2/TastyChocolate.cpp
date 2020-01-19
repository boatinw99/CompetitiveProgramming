#include<bits/stdc++.h>
using namespace std ;
const int N = 1009,T=3009;
int dp[T][N];
main()
{
    int i,n,x,j ;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        scanf("%d",&x);
        dp[j-1][j]=1e6;
        for(i=j;i<=3000;i++)
        {
            if(i!=x)
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+1);
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    printf("%d",dp[3000][n]);
}
