#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pii ;
#define fi first
#define se second
const int N = 1e5+9 , mod = 1e9+7 ;
int fact[N],inv[N];
pii a[N];
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    int ret = pow2(a,p>>1);
    ret = 1ll*ret*ret %mod ;
    if(p&1)ret=1ll*ret*a%mod ;
    return ret ;
}
void pre_process()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*1ll*i%mod;
    for(int i=0;i<N;i++)inv[i]=pow2(fact[i],mod-2);
}
int di(pii a,pii b,pii c)
{
    pii vec1(b.fi-a.fi,b.se-a.se),vec2(c.fi-a.fi,c.se-a.se);
    if(vec1.fi*vec2.se-vec2.fi*vec1.se<0)return 1 ;
    else if(vec1.fi*vec2.se-vec2.fi*vec1.se==0)return 0 ;
    else return 2 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k ;
    pii P ;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)cin >> a[i].fi >> a[i].se ;
    cin >> P.fi >> P.se ;
    pre_process();
    int ans = fact[n]*1ll*inv[n-k]%mod*inv[k]%mod;
    for(int i=1,r=2;i<=n;i++)
    {
        while(di(a[i],a[r%n+1],P)!=1)r=r%n+1;
        int sz = r-i;
        if(sz<=0)sz+=n;
        if(sz>=k-1)
        {
            int add = fact[sz]*1ll*inv[sz-k+1]%mod*inv[k-1]%mod;
            ans=(ans-add+mod)%mod;
        }
    }
    cout << ans ;
}
