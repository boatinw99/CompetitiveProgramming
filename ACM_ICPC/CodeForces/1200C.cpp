#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll INF = 1e18 ;
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
ll n,m ;
int a,b ;
ll x,y ;
ll gc ;
ll finda(ll u)
{
    return (u-1)/(n/gc) ;
}
ll findb(ll u)
{
    return (u-1)/(m/gc) ;
}
int solve()
{
    ll ca,cb ;
    if(a==1)ca=finda(x);
    else ca=findb(x);
    if(b==1)cb=finda(y);
    else cb=findb(y);
    //printf("wtf %lld %lld \n",ca,cb);
    return ca==cb ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ;
    cin >> n >> m >> q ; 
    gc=__gcd(n,m) ;
    ///gc=max(n,m)/gc;
    while(q--)
    {
        cin >> a >> x >> b >> y ;
        cout << (solve()==1?"YES":"NO") << '\n' ;
    }
    return 0 ;
}