#include<bits/stdc++.h>
using namespace std ;
const int N = 59 ,MOD = 2009;
int dp[N][N];
main()
{
    int Q,n,k,i,j,x ;
    scanf("%d",&Q);
    ///Preprocess
    dp[0][0]=1;
    for(i=1;i<N;i++)
    {
        dp[i][0]=1;
        for(j=1;j<i;j++)
        {
            dp[i][j]=dp[i-1][j];
            for(k=0;k<i-1;k++)
            {
                for(x=0;x<=j;x++)
                {
                    dp[i][j]+=dp[k][x]*dp[i-k-1][j-x-1];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    while(Q--)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[n][k]);
    }
}
