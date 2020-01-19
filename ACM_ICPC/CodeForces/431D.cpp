#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const ll M = 1ll<<60 , INF = 1e18+9 ;
const ll inf = 1e9 ; 
const int K = 109 ; 
ll m ; 
ll dp[K][K];
int k ;
void pre_process()
{
    dp[0][0]=1;
    for(int i=1;i<K;i++)
    {
        dp[i][0]=1 ;
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            dp[i][j]=min(dp[i][j],INF);
        }
    }
}
ll popcount(ll x)
{
    int cnt = 0 ;
    for(ll bits=M;bits;bits>>=1)
    {
        cnt+=(bits&x)==bits;
    }
    return cnt ; 
}
ll f(ll x)
{
    ll cnt = popcount(x); 
    int bit1 = 0 , embit = 60 ;
    for(ll bits=M;k-bit1>=0&&embit;bits>>=1,embit--)
    {
        if(bits&x)
        {
            cnt+=dp[embit][k-bit1];
            cnt = min(cnt,INF);
            bit1++;
        }
    }
    return cnt ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    pre_process();
    cin >> m >> k ;
    ll l = 1 , r = 1e18 ;
    while(l<=r)
    {
        ll mid = l+r >> 1 ;
        ll cnt = f(mid<<1)-f(mid);
        if(cnt==m)
        {
            cout << mid << '\n' ;
            break ;
        }
        else if(cnt<m)l=mid+1;
        else r=mid-1;
    }
    return 0 ;
}