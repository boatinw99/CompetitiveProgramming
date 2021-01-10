#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 29 , inf = 2e9 , mod = 1e9+7 ;
string s[N],t[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> t[i];
    }
    int q ;
    cin >> q ;
    while(q--)
    {
        int nw ; 
        cin >> nw ; 
        nw--;
        cout << s[nw%n] << t[nw%m] << '\n' ;
    }
    return 0 ;
}