#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ; 
typedef pair<int,ll> pil ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 1e5+9 , mod = 1e9+7, inf = 1e9 ; 
vector<int> V ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        int u ;
        cin >> u ;
        V.emplace_back(u);
    }
    sort(V.begin(),V.end(),greater<int>());
    ll x=0,y=0 ;
    for(int l=0,r=n-1;l<=r;l++,r--)
    {
        if(l==r)
        {
            x+=V[l];
        }
        else x+=V[l],y+=V[r];
    }
    ll ans = x*x+y*y ; 
    cout << ans << '\n' ;
    return 0 ;
}