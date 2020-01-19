#include<bits/stdc++.h>
using namespace std ;
const int N = 3009;
int a[N],b[N];
int dp[2][N];
main()
{
    int n,i,j,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        x=i&1;
        for(j=1;j<=n;j++)
        {
            dp[x][j]=max(dp[x^1][j],dp[x][j-1]);
            if(a[i]==b[j])
            {
                dp[x][j]=dp[x^1][j-1]+1;
            }
        }
    }
    printf("%d",dp[x][n]);
}
