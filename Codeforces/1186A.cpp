#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const ll INF = 1e18 ; 
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
int n,m ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int k ;
    cin >> n >> m >> k ;
    if(m<n||k<n)
    {
        cout << "No" << '\n' ;
        return 0 ;
    }
    cout << "Yes" << '\n' ;
    return 0 ;
}