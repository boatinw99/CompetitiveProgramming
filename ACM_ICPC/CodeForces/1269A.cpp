#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const int N = 1e5+9 , mod = 1e9+7 ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    if(n&1)
    {
        cout << 9+n << " " << "9" << '\n' ;
    }
    else 
    {
        cout << 4+n << " " << "4" << '\n' ;
    }
    return 0 ;
}