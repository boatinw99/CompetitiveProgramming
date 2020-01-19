#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll n,x,y ;
    cin >> n >> x >> y ;
    if(n>=x)
    {
        cout << x-1 ;
        return 0 ;
    }
    ll ans = 0;
    if((y-n*(n-1)/2)%n==0)ans = max(ans,(y-n*(n-1)/2)/n+n-1);
    for(ll i=x-1,sum=0;i>=0&&sum<y;i--)
    {
        sum+=i;
        ll sz = n-(x-i+1);
        if(sz<0)break;
        if(sum+sz*(sz+1)/2==y)
        {
            ans=x-1;
            break;
        }
    }
    cout << ans ;
    return 0 ;
}
