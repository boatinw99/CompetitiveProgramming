#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const ll INF = 1e18 ; 
const int N = 1e5+9 , mod = 1e9+7 , inf = 2e9 ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll n,p,d,w ;
    cin >> n >> p >> w >> d ; 
    ll lcm = w*d/__gcd(w,d);
    ll turnwin = (p)/w;
    ll pwin = turnwin*w ;  
    ll premain = p-pwin; //remained
    ll turndraw = 0 ;
    if(premain>0)turndraw=(premain/d);
    int cnt = 1000000;
    while(turnwin*w+turndraw*d!=p&&turnwin+turndraw<=n&&turnwin>0&&cnt>0)
    {
        premain = p-(turnwin*w+turndraw*d);
        turnwin--;
        premain+=w;
        while(turnwin*w+turndraw*d!=p&&premain>=d)
        {
            turndraw++;
            premain-=d;
        }
        cnt--;
    }
    if(turnwin*w+turndraw*d==p&&turndraw+turnwin<=n)
    {
        ll turnremain = n-turndraw-turnwin;
        cout << turnwin << " " << turndraw << " " << turnremain << '\n' ;
        return 0 ;
    }
    cout << "-1" << '\n' ;
    return 0 ;
}