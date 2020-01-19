#include<bits/stdc++.h>
using namespace std ;
const int N = 509;
int dp[N][N];
main()
{
    int Q,i,j,n,m,x;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&x);
                dp[i][j]=dp[i-1][j];
                if(j-1>=1)dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                if(j+1<=m)dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                dp[i][j]+=x;
            }
        }
        int ans=INT_MAX;
        for(j=1;j<=m;j++)
        {
            ans=min(ans,dp[n][j]);
        }
        printf("%d\n",ans);
    }
}
