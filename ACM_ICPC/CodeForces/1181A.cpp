#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const double pi = 3.141592653589 ; 
const ll INF = 1e18 ; 
const int N = 1e5+9 , mod = 1e9+7 , inf = 1e9 ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll a,b,c ;
    cin >> a >> b >> c ; 
    ll ans = (a/c)+(b/c);
    ll md1 = a%c , md2 = b%c ; 
    ll give = 0 ;
    if(md1+md2>=c)
    {
        ans++;
        if(md1<md2)
        {
            give = c-md2 ;
        }
        else 
        {
            give = c-md1 ;
        }
    }
    cout << ans << " " << give << '\n' ; 
    return 0 ;
}