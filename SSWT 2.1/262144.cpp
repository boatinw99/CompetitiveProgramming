#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9,sz=60;
int dp[sz][N],a[N];
main()
{
    int n,i,j,ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<sz;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[j]==i)dp[i][j]=j+1;
            else dp[i][j]=dp[i-1][dp[i-1][j]];
            if(dp[i][j])ans=i;
        }
    }
    cout << ans ;
}
