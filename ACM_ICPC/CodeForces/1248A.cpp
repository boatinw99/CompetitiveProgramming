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
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--)
    {
        int cnt0=0,cnt1=0,n,m ;
        ll ans = 0 ;
        cin >> n ;
        for(int i=1;i<=n;i++)
        {
            int u ;
            cin >> u ;
            if(u&1)cnt1++;
            else cnt0++;
        }
        cin >> m ;
        for(int i=1;i<=m;i++)
        {
            int u ;
            cin >> u ;
            if(u&1)ans+=cnt1;
            else ans+=cnt0;
        }
        cout << ans << '\n' ;
    }
    return 0 ;
}