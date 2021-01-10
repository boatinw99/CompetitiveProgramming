#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const int N = 1e5+9 ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int x,y,z ; 
    cin >> x >> y >> z ;
    if(x+z<y)
    {
        cout << "-" ;
    }
    else if(y+z<x)
    {
        cout << "+" ;
    }
    else if(x==y&&z==0)
    {
        cout << "0" ;
    }
    else cout << "?" ;
    return 0 ;
}