#include<bits/stdc++.h>
using namespace std ;
const int N = 1e4+9,mid=5e3+3,md=1e9+7;
int dp[N/10+1][N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,n,m,x,ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        for(j=N-1;j-x>=0;j--)dp[i][j-x]=(dp[i-1][j]+dp[i][j-x])%md;
        for(j=0;j+x<N;j++)dp[i][j+x]=(dp[i-1][j]+dp[i][j+x])%md;
        dp[i][x+mid]=(dp[i][x+mid]+1)%md;
        dp[i][mid-x]=(dp[i][mid-x]+1)%md;
        ans=(ans+dp[i][mid])%md;
    }
    cout << ans ;
}
