#include<bits/stdc++.h>
using namespace std ;
const int N = 509;
int a[N][N];
int dp[3][N][59];
main()
{
    int n,k,x,y,z,i,j,d ;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n+1;i++)
    {
        for(j=2;j<=n+1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    x=2;y=1;z=0;
    int max1=0;
    for(i=2;i<=n+1;i++)
    {
        for(j=2;j<=n+1;j++)
        {
            max1=max(dp[x][j-2][k],dp[y][j-1][k]);
            max1=max(max1,dp[z][j][k]);
            max1+=a[i][j];
            dp[x][j][1]=max1;
            max1=max(dp[x][j-1][k],dp[y][j][k]);
            dp[x][j][1]=max(dp[x][j][1],max1);
            for(d=1;d<=k;d++)
            {
                dp[x][j][d]=max(dp[x][j][d],dp[x][j-1][d]);
                dp[x][j][d]=max(dp[x][j][d],dp[y][j][d]);
                dp[x][j][d]=max(dp[x][j][d],dp[x][j][d-1]);
        dp[x][j+1][d+1]=max(dp[x][j+1][d+1],dp[x][j][d]+a[i][j+1]);
        dp[z][j][d+1]=max(dp[z][j][d+1],dp[x][j][d]+a[i+1][j]);
            }
        }
        if(x==2)
        {
            x=0;y=2;z=1;
        }
        else if(x==0)
        {
            x=1;y=0;z=2;
        }
        else if(x==1)
        {
            x=2,y=1,z=0;
        }
    }
    printf("%d",dp[y][n+1][k]);
}
