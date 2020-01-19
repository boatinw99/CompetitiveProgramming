#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int mod = 1e9+7 , M = 70 , K = 1e4+9 ;
ll n,dp[K][M];
ll inv[M];
int k ;
ll powap(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret=ret*ret%mod ;
    if(p&1)ret=ret*a%mod ;
    return ret ;
}
ll comp(ll p,ll d)
{
    //memset(dp,0,sizeof dp);
    dp[0][d]=1;
    for(int i=1;i<=k;i++)
    {
        ll pref = 0 ;
        for(int j=d;j>=0;j--)
        {
            pref+=dp[i-1][j]*inv[j+1]%mod;
            pref%=mod ;
            dp[i][j]=pref;
        }
    }
    ll exp = 0 ; // expected value 
    for(int i=0;i<=d;i++)
    {
        exp += powap(p,i)*dp[k][i]%mod;
        exp%=mod ;
    }
    dp[0][d]=0;
    return exp ;
}
void pre_process()
{
    for(int i=1;i<M;i++)
    {
        inv[i]=powap(i,mod-2);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    pre_process();
    cin >> n >> k ;
    ll ans = 1 ;
    ll tmp = n ; 
    for(ll i=2;i*i<=n;i++)
    {
        int cnt = 0 ;
        while(tmp%i==0)
        {
            tmp/=i ;
            cnt++;
        }
        if(cnt>0)
        {
            ll ret = comp(i,cnt);
            ans = ans*ret % mod ; 
        }
    }
    if(tmp>1)
    {
        ans = ans*comp(tmp,1)%mod;
    }
    cout << ans << '\n' ;
    return 0 ;
}