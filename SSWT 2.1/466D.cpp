#include<bits/stdc++.h>
using namespace std ;
const int N = 2009 , md = 1e9+7 ;
int a[N],dp[N][N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,h ;
    cin >> n >> h ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        if(a[i]>h)
        {
            cout << "0" ;
            return 0 ;
        }
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        int val = h-a[i] ;
        int j=val-1;
        dp[i][val]=dp[i-1][val]; ///do nothing
        if(val)dp[i][val-1]=(dp[i][val-1]+1ll*j*dp[i-1][val-1]%md)%md; ///close and open
        if(val)dp[i][val]=(dp[i][val]+dp[i-1][val-1])%md; ///open interval
        if(val)dp[i][val-1]=(dp[i][val-1]+dp[i-1][val-1])%md; ///open and close
        if(val)dp[i][val-1]=(dp[i][val-1]+1ll*val*dp[i-1][val]%md)%md; ///close interval
    }
    cout << dp[n][0];
}


