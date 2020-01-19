#include<bits/stdc++.h>
using namespace std ;
const int N = 1009 ;
int a[N],dp[N][N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j ;
    cin >> n >> k ;
    for(i=2;i<=n+1;i++)
    {
        cin >> a[i] ;
        dp[i][0]=max(dp[i-1][0],dp[i-2][0]+a[i]);
        for(j=1;j<=k;j++)
        {
            dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+a[i],dp[i-2][j]+a[i]});
        }
    }
    int ans = 0 ;
    cout << dp[n+1][k] ;
}
