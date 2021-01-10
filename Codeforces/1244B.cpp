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
const int N = 1e5+9 , mod = 1e9+7 , inf = 1e9 ;

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--)
    {
        int n ;
        string s ;
        cin >> n ;
        cin >> s ;
        int l=inf,r=-inf ; 
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        r++;
        l++;
        int ans = n ;
        ans = max(ans,r*2);
        ans = max(ans,(n-l+1)*2);
        cout << ans << '\n' ;
    }
    return 0 ;
}