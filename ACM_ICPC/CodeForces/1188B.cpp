#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
map<ll,int> mp ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    ll p,k ; 
    cin >> n >> p >> k ;
    long long ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        ll val ; 
        cin >> val ; 
        ll tmp = (val*val%p*val%p*val%p-k*val+p*p)%p; 
        ans+=mp[tmp];
        mp[tmp]++;
    }
    cout << ans << '\n' ;
    return 0 ;
}