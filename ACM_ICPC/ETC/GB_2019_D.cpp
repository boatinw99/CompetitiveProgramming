#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define mid (l+r>>1)
#define fi first
#define se escond 
const int N = 1e5+9 , mod = 1e9+7 ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll a,b,c ; 
    cin >> a >> b >> c ;
    cout << a+b+c-__gcd(a,b)-__gcd(a,c)-__gcd(b,c)+__gcd(__gcd(a,b),c) << '\n' ; 
    return 0 ;
}