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
ll qs[N];
ll arr[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    ll k ;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++)
    {
        qs[i]=qs[i-1]+arr[i];
    }
    ll ans = INF ;
    for(int L=1;L<=n;L++)
    {
        ll sum = arr[L]*L-qs[L];
        ll rmn = k-sum ;
        ///num = L 
        if(rmn<0)continue;
        ll l=arr[L]-1,r=arr[n];
        while(l+1<r)
        {
            ///mid 
            int idx = lower_bound(arr+1,arr+1+n,mid)-arr;
            ll tmp = (qs[n]-qs[idx-1])-mid*(n-idx+1);
            if(tmp<=rmn)r=mid ;
            else l=mid ;
        }
        ans = min(ans,r-arr[L]);
        //return 0 ;
    }
    for(int R=n;R>=1;R--)
    {
        ll sum = (qs[n]-qs[R-1])-arr[R]*(n-R+1);
        ll rmn = k-sum;
        if(rmn<0)continue ;
        ll l = arr[1],r=arr[R]+1;
        while(l+1<r)
        {
            int idx = upper_bound(arr+1,arr+1+n,mid)-arr-1;
            ll tmp = idx*mid-qs[idx];
            if(tmp<=rmn)l=mid ;
            else r=mid ;
        }
        ans = min(ans,arr[R]-l);
    }
    cout << ans << '\n' ;
    return 0 ;
}