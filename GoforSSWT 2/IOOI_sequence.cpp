#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5009,MOD=2553;
int dp[N][2],qs[N][2];
int pr[N];
main()
{
    int n,k,i,j,a=0,b=1 ;
    ll ans=0,x ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        if(i<=k)dp[i][0]=1;
        qs[i][0]=(qs[i-1][0]+dp[i][0]-dp[max(0,i-k)][0]+MOD)%MOD;
        pr[0]=dp[n][0];
    }
    for(j=1;j<=n-1;j++)
    {
        swap(a,b);
        for(i=1;i<=n;i++)
        {
            dp[i][a]=qs[i-1][b];
            qs[i][a]=(qs[i-1][a]+dp[i][a]-dp[max(0,i-k)][a]+MOD)%MOD;
        }
        pr[j]=dp[n][a];
    }
    for(j=0;j<=n;j++)
    {
        if(j*k>=n)
        {
            x=pr[j-1];
            x=x*x*x;
            ans=(ans+x)%MOD;
        }
    }
    printf("%lld",ans);
}
