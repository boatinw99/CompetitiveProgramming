#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 ;
int dp[N][N],a[N];
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k,i,j,l=1 ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        while(a[i]-a[l]>5)l++;
        for(j=1;j<=k;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[l-1][j-1]+(i-l+1));
        }
    }
    cout << dp[n][k] ;
}
