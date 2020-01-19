#include<bits/stdc++.h>
using namespace std ;
const int N = 3009;
int a[N],n,k;
int dp[N][N];
void optimize(int j)
{
    for(int i=2;i<k;i++)
    {
        dp[i][j]=min(dp[i][j],dp[i-1][j]);
    }
}
main()
{
    int i,j ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=1;j<=k;j++)
    {
        for(i=1;i<j;i++)
        {
            dp[i][j]=a[j]+a[j-i];
        }
        optimize(j);
    }
    for(j=k+1;j<=n;j++)
    {
        for(i=1;i<k;i++)
        {
            dp[i][j]=a[j]+dp[k-i][j-i];
        }
        optimize(j);
    }
    int ans=3e6 ;
    for(j=n,i=k-1;j>=n-k+2;j--,i--)
    {
        ans=min(ans,dp[i][j]);
    }
    printf("%d",ans);
}
