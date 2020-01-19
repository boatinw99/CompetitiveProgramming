#include<bits/stdc++.h>
using namespace std ;
const int N = 209 , M = 1009 , md=1e9+7;
int dp[N][N][M],a[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,K,i,j,k,d,l ;
    cin >> n >> K ;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    dp[0][0][0]=1;
    a[0]=a[1];
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            int val = j*(a[i]-a[i-1]);
            for(k=0;k+val<=K;k++)
                dp[i][j][k+val]=(dp[i][j][k+val]+dp[i-1][j][k])%md;
            for(k=0;k+val<=K;k++)
                dp[i][j+1][k+val]=(dp[i][j+1][k+val]+dp[i-1][j][k])%md;
            if(j)for(k=0;k+val<=K;k++)
                dp[i][j-1][k+val]=(dp[i][j-1][k+val]+1ll*j*dp[i-1][j][k])%md;
            for(k=0;k+val<=K;k++)
                dp[i][j][k+val]=(dp[i][j][k+val]+1ll*j*dp[i-1][j][k])%md;
        }

    }
    int ans=0 ;
    for(k=0;k<=K;k++)ans=(ans+dp[n][0][k])%md;
    cout << ans ;
}
