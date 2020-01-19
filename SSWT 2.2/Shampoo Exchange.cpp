#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll inf = 1e18 ;
const int N = 1e5+9 ;
int a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,X ;
    ll sum = 0 ;
    cin >> n >> X ;
    for(int i=1;i<=n;i++)cin >> a[i],sum+=a[i] ;
    sort(a+1,a+1+n,greater<int>());
    int sz = (sum-1)/X + 1 ;
    ll l = a[sz+1] , r = inf ;
    ll rmn = 0 ;
    for(int i=sz+1;i<=n;i++)rmn+=a[i];
    while(l<r)
    {
        ll mid = l+r >> 1 , times = 0 ;
        for(int i=1;i<=sz;i++)times+=min(mid,1ll*X-a[i]);
        if(times>=rmn)r=mid;
        else l=mid+1;
    }
    cout << sz << " " << l ;
    return 0 ;
}
