#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 3e5+9 , inf = 2e9 , mod = 1e9+7 ;
ll fact[N],m ;
void pre_process()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=fact[i-1]*i%m;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n >> m ;
    pre_process();
    ll ans = fact[n]*n%m ;
    for(int i=1;i<n;i++)
    {
        ans+=1ll*(n-i)*(n-i)%m*fact[i+1]%m*fact[n-i-1]%m;
        ans%=m;
    }
    cout << ans << '\n' ;
    return 0 ;
}