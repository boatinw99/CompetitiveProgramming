#include<bits/stdc++.h>
using namespace std ;
const int N = 5009,MOD=29947;
int dp[N][N];
main()
{
    int x,y,z,i,j;
    scanf("%d %d %d",&x,&y,&z);
    x--; y--; z--;
    for(i=0;i<N;i++)
    {
        dp[0][i]=1;
        dp[i][0]=1;
    }
    for(i=1;i<N;i++)
    {
        for(j=1;j<N;j++)
        {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
        }
    }
    int ans=0;
    for(i=1;i<=y;i++)
    {
        for(j=1;j<=x;j++)
        {
            ans=(ans+dp[i-1][j-1]*dp[z][y-i+x-j])%MOD;
        }
    }
    ans=(ans+dp[z][y+x])%MOD;
    printf("%d",ans%MOD);
}
