#include<bits/stdc++.h>
using namespace std ;
const int N = 509 ;
vector<int> a[256];
string s ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,T ;
    char c ;
    cin >> n >> T ;
    for(i=1;i<=n;i++)
    {
        cin >> c;
        a[c].emplace_back(i);
    }
    while(T--)
    {
        cin >> s ;
    }
}
