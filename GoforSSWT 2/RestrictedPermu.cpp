#include<bits/stdc++.h>
using namespace std ;
const int N = 2009,MOD=1e9+7 ;
int dp[N][N];
main()
{
    int n,i,j,k,sum=0;
    scanf("%d",&n);
    dp[1][1]=1;
    for(j=2;j<=n;j++)
    {
        scanf("%d",&k);
        sum=0;
        if(k==1)
        {
            for(i=2;i<=j;i++)
            {
                sum+=dp[i-1][j-1];
                sum%=MOD;
                dp[i][j]=sum;
            }
        }
        else
        {
            for(i=j-1;i>=1;i--)
            {
                sum+=dp[i][j-1];
                sum%=MOD;
                dp[i][j]=sum;
            }
        }
    }
    sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=dp[i][n];
        sum%=MOD;
        //printf("%d ",dp[i][n]);
    }
    printf("%d",sum);
}
