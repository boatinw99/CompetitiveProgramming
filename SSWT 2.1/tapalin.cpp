#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e9+7 ;
int pow2(int a,int n)
{
    int x ;
    if(n==1)return a;
    x=pow2(a,n/2);
    x=(1ll*x*x)%MOD;
    if(n&1)x=(1ll*x*a)%MOD;
    return x ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n;
    cin >> T;
    int inv = pow2(25,1e9+5);
    while(T--)
    {
        cin >> n ;
        if(n&1)
            cout << (((1ll*(pow2(26,n/2+1)-26)*2)%MOD*inv)%MOD
                +pow2(26,n+1>>1))%MOD;
        else cout << ((1ll*(pow2(26,n/2+1)-26)*2)%MOD*inv)%MOD;
        cout << '\n';
    }
}
