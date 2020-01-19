#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 8*840+9 ;
bool dp[N][N];
ll a[9];
main()
{
    int n=8,i,j ;
    ll x,cnt=0,lcm=840,W=0,ans=0 ;
    cin >> W ;
    for(i=1;i<=8;i++)cin >> a[i] ;
    for(i=8;i>=1;i--)
    {
        ll cst = lcm/i ;
        ll tmp = min(W/lcm,a[i]/cst) ;
        ans+=tmp*lcm ;
        W-=tmp*lcm ;
        a[i]-=tmp*cst ;
        a[i]%=lcm+1 ;
    }
    int p = 0;
    ll mx=0;
    dp[0][0]=1 ;
    for(i=1;i<=8;i++)
    {
        while(a[i]--)
        {
            p++;
            for(j=0;j+i<N;j++)
            {
                dp[p][j+i]=max(dp[p-1][j],dp[p][j+i]);
            }
            for(j=0;j<N;j++)dp[p][j]=max(dp[p-1][j],dp[p][j]);
        }
    }
    for(j=0;j<N&&j<=W;j++)if(dp[p][j])mx=j ;
    cout << ans+mx;
}
