#include<bits/stdc++.h>
using namespace std ;
const int MX = 1e6 ; 
void pr(int n,int k)
{
    for(int i=1;i<=n;i++)
    {
        int res = min(MX,k);
        cout << res << " "; 
        k-=res ;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int k ;
    cin >> k ;
    if(k&1)
    {
        cout << 1003 << '\n' << 1 << " " << -2 << " " ;
        pr(1001,1ll*k+2+1001>>1);
    }
    else 
    {
        cout << 1002 << '\n' << 1 << " " << -2 << " ";
        pr(1000,1ll*k+2+1000>>1);
    }
}