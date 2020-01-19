#include<bits/stdc++.h>
using namespace std ;
const int N = 1009,MOD=10001;
int dp[N];
main()
{
    int n,i,j,x ;
    scanf("%d",&n);
    dp[0]=1; dp[1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            dp[i]=(dp[i]+dp[j]*dp[i-1-j])%MOD;
        }
    }
    printf("%d",dp[n]);
}
