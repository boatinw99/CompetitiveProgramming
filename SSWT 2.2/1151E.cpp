/**
 *      Author : boatinw99
 *      Date : 4.5.2019 15:18 - 15:22
 */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
int a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans = 0 ;
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
        ans+=1ll*a[i]*(n-a[i]+1);
    }
    for(int i=1;i<n;i++)
    {
        int u = min(a[i],a[i+1]) , v=max(a[i],a[i+1]);
        ans-=1ll*(u)*(n-v+1);
    }
    cout << ans ;
}
