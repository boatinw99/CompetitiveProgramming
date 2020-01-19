#include<bits/stdc++.h>
using namespace std ;
const int N = 5009;
int A[N],B[N];
int dp[2][N];
main()
{
    int n,m,k,i,j,x=0 ;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    for(i=1;i<=m;i++)scanf("%d",&B[i]);
    for(i=1;i<=n;i++)
    {
        dp[0][i]=1;
    }
    int max1=0,min1=1e6;
    for(i=1;i<=m;i++)
    {
        x=i&1;
        dp[x][0]=i;
        min1=dp[x^1][0];
        for(j=1;j<=n;j++)
        {
            dp[x][j]=dp[x^1][j-1]+(B[i]!=A[j]);
            dp[x][j]=min(dp[x][j],dp[x^1][j]+1);
            dp[x][j]=min(dp[x][j],min1+(B[i]!=A[j])+1);
            if(dp[x][j]<=k)max1=i;
            min1=min(min1,dp[x^1][j]);
        }
    }
    printf("%d",max1);
}
