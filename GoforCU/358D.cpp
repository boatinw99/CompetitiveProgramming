#include<bits/stdc++.h>
using namespace std ;
int n;
const int N = 3009;
int dp[4][N];
int a[3][N];
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=0;i<3;i++)
    {
        for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    if(n==1)printf("%d",a[0][1]);
    else if(n==2)
    {
        printf("%d",max(a[0][1]+a[1][2],a[1][1]+a[0][2]));
    }
    else
    {
        dp[0][1]=a[0][1];
        dp[1][1]=INT_MIN;
        dp[2][1]=a[1][1];
        dp[3][1]=INT_MIN;
        for(j=2;j<=n;j++)
        {
            dp[0][j]=max(dp[2][j-1],dp[3][j-1])+a[0][j];
            dp[1][j]=max(dp[1][j-1],dp[0][j-1])+a[1][j];
            dp[2][j]=max(dp[2][j-1],dp[3][j-1])+a[1][j];
            dp[3][j]=max(dp[0][j-1],dp[1][j-1])+a[2][j];
        }
        printf("%d",max(dp[0][n],dp[1][n]));

    }
}
