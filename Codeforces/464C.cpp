#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ; 
typedef long long ll ; 
typedef pair<ll,ll> pll ; 
#define fi first
#define se second 
const int mod = 1e9+7 ; 
pll dp[10]; // sum digit 
pair<int,string> S[N];
ll pw10(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = pw10(a,p>>1);
    ret = ret*ret%mod ; 
    if(p&1)ret=ret*a%mod ;
    return ret ; 
}
pll get_sum(string s)
{
    int n = s.size();
    ll sum = 0 ;
    ll dig = 0 ;
    for(int i=n-1;i>=0;i--)
    {
        sum+=dp[s[i]-'0'].fi*pw10(10,dig)%mod;
        sum%=mod ;
        dig+=dp[s[i]-'0'].se;
        dig%=mod-1;
    }
    return {sum,dig} ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    string s ; 
    int n ; 
    cin >> s ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        char c ;
        string tmp ; 
        cin >> tmp ; 
        S[i].fi = tmp[0] - '0' ;
        S[i].se = tmp.substr(3);
        //cout << S[i].se << '\n' ;
    }
    for(int i=0;i<10;i++)dp[i]={i,1};
    for(int i=n;i>=1;i--)
    {
        pll ret = get_sum(S[i].se);
        dp[S[i].fi] = ret ; 
    }
    //printf("check %lld %lld\n",dp[2].fi,dp[2].se);
    cout << get_sum(s).fi << '\n' ;
    return 0 ;
}