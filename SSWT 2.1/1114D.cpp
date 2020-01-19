#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 ;
int dp[N][N],a[N],sz=0;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int x,n,i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        if(x==a[sz])continue ;
        a[sz+1]=x;
        sz++;
    }
    for(i=sz;i>=1;i--)
    {
        for(j=i+1;j<=sz;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            if(a[i]==a[j])dp[i][j]=dp[i+1][j-1]+1;
        }
    }
    cout << sz-1-dp[1][sz];
}
