#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
#define fi first
#define se second 
const int N = 1e5+9 , K = 1024 , mod = 1e9+7 ; 
map<int,int> mp ; 
ll fact[N],inv[N],dp[K];
ll pow2(ll a,ll p)
{
    if(p==0)return 1 ;
    ll res = pow2(a,p>>1);
    res = res*res % mod ; 
    if(p&1)res = res*a %mod;
    return res ; 
}
void pre_compute()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=1ll*fact[i-1]*i %mod ;
    }
    for(int i=0;i<N;i++)
    {
        inv[i]=pow2(fact[i],mod-2);
    }
}
bool Is_lucky(int x)
{
    int tmp = x ; 
    while(x)
    {
        if((x%10!=4)&&(x%10!=7))return 0 ;
        x/=10 ; 
    }
    return 1 ;
}
ll get(ll n,ll k)
{
    if(n<k)return 0 ;
    return fact[n]*inv[k]%mod*inv[n-k]%mod ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    pre_compute();
    int n,k,unlucky = 0 ; 
    cin >> n >> k ; 
    for(int i=1;i<=n;i++)
    {
        int val ; 
        cin >> val ;
        if(Is_lucky(val))
        {
            mp[val]++;
        } 
        else unlucky++; 
    }
    dp[0]=1;
    for(auto it:mp)
    {
        for(int j=K-2;j>=0;j--)
        {
            dp[j+1]+=dp[j]*it.se%mod;       
            dp[j+1]%=mod ;
        }
    }
    ll ans = 0 ;
    for(int i=0;i<=min(k,K-1);i++)
    {
        ans+=dp[i]*get(unlucky,k-i);
        ans%=mod;
    }
    cout << ans << '\n' ;
    return 0 ;
}