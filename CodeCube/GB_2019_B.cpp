#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll mx = 1e18+1 ; 
const int N = 1e5+9 , mod = 1e9+7 ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll n ; 
    cin >> n ;
    ll l = 0 , r = 1e18 ; 
    while(l+1<r)
    {
        ll bell = mid/7 ;
        ll star = bell/12 ; 
        ll beauty = min(bell*23,mx)+min(star*98,mx) ;
        if(beauty>=n)r=mid;
        else l=mid;
        //printf("check %lld \n",beauty);
        assert(beauty>=0);
    }
    cout << r << '\n';
    return 0 ;
}