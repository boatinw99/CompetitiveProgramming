#include<bits/stdc++.h>
using namespace std ;
const int N = 2009 ;
int dp[2][N];
main()
{
    int n,i,j,x,in ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&in);
        x=i&1;
        dp[x][0]=max(dp[x^1][0],dp[x^1][2]-in);
        for(j=1;j<=i;j++)dp[x][j]=max(dp[x^1][j-1]+in,dp[x^1][j+2]-in);
    }
    printf("%d",dp[x][0]);
}
