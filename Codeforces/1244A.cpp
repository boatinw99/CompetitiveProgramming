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
    int T ;
    cin >> T ;
    while(T--)
    {
        int a,b,c,d,k,x=0,y=0;
        cin >> a >> b >> c >> d >> k ;
        while(a>0)a-=c,x++;
        while(b>0)b-=d,y++;
        if(x+y<=k)
        {
            cout << x << " " << y << '\n' ;
        }
        else cout << "-1" << '\n' ;
    }
    return 0 ;

}