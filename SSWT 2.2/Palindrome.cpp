#include<bits/stdc++.h>
using namespace std ;
const int N = 5009 ;
int dp[N][N];
char c[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> c[i] ;
    for(i=n;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
            if(c[i]==c[j])dp[i][j]=dp[i+1][j-1];
        }
    }
    cout << dp[1][n];
}
