#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,MAX=1e9,MID=100;
int dp[N][209];
main()
{
    int Q,n,k,i,j,a,b ;
    scanf("%d",&Q);
    for(j=0;j<=200;j++)dp[0][j]=MAX;
    while(Q--)
    {
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=200;j++)dp[i][j]=MAX;
        }
        dp[0][100]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            for(j=MID-k;j<=MID+k;j++)
            {
                if(dp[i-1][j]>=0)
                dp[i][j+1]=dp[i-1][j]+a;
            }
            for(j=MID-k;j<=MID+k;j++)
            {
                if(dp[i-1][j]>=0)
                {
                    dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+b);
                }
                dp[i-1][j]=MAX;
            }
        }
        int ans=INT_MAX;
        for(j=MID-k;j<=MID+k;j++)
        {
            //printf("%d ",dp[n][j]);
            ans=min(ans,dp[n][j]);
        }
        printf("%d\n",ans);
    }
}
