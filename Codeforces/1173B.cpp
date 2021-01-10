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
    int n,m ;
    cin >> n ; 
    for(m=1;m;m++)
    {
        if(2*m-1>=n)break;
    }
    cout << m << '\n' ; 
    int i ; 
    for(i=1;i<=m&&i<=n;i++)
    {
        cout << "1 " << i << '\n' ; 
    }
    for(int j=2;i<=n;i++,j++)
    {
        cout << j << " " << m << '\n' ;
    }
    return 0 ;
}