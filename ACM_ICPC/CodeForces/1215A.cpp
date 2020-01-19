#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 2e5+9 , inf = 2e9 , mod = 1e9+7 ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int a1,a2,k1,k2,n ;
    cin >> a1 >> a2 >> k1 >> k2 >> n ;
    int mn = 0 , mx = 0 ;
    mn = max(0,n-(a1*(k1-1)+a2*(k2-1)));
    mn = min(mn,a1+a2);
    if(k1>k2)
    {
        swap(a1,a2);
        swap(k1,k2);
    }   
    while(a1>0&&n>=k1)
    {
        n-=k1;
        mx++;
        a1--;
    }
    while(a2>0&&n>=k2)
    {
        n-=k2;
        mx++;
        a2--;
    }
    cout << mn << " " << mx << '\n' ;
    return 0 ;
}