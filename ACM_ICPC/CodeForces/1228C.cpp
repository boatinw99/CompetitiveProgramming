#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ;
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
vector<int> prime; 
ll powap(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret=1ll*ret*ret%mod;
    if(p&1)ret=a%mod*1ll*ret%mod;
    return ret ;
}
ll perform(ll pi,ll n)
{
    int k = 0 ;
    ll pp = 1 ; 
    ll tmp = n ;
    while(tmp>=pi)
    {
        k++;
        tmp/=pi ;
        pp*=pi ;
    }
    ///pi^k
    ll product=1 ;
    ll exnum = 0 ;
    for(int i=k;i>0;i--,pp/=pi)
    {
        ll t = n/(pp);
        ll now = t-exnum ;
        //printf("wtf %lld %lld %lld \n",pp,t,now);
        ll ret = powap(pp,now);
        product=product*ret%mod;
        exnum = t ;
    }
    //printf("wtf really %lld \n",product);
    return product ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int x ;
    ll n ;
    cin >> x >> n ;
    int tmp = x;
    for(int d=2;d*d<=x;d++)
    {
        if(tmp%d==0)
        {
            prime.push_back(d);
            while(tmp%d==0)tmp/=d;
        }
    }
    if(tmp>1)prime.push_back(tmp);
    ll ans = 1 ;
    for(auto it:prime)
    {
        ll ret = perform(it,n);
        ans=ans*ret%mod ;
    }
    cout << ans << '\n' ;
    return 0 ; 
}