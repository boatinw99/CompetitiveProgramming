#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , bit = 61 ;
ll a[N];
int n ;
int main()
{
    cin >> n ;
    int cnt = 0 ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    for(int j=bit-1;j>=0;j--)
    {
        ll tmp = 0 ;
        for(int i=1;i<=n;i++)
        {
            if((1ll<<j)&a[i])
            {
                tmp = a[i];
                break;
            }
        }
        if(!tmp)continue ;
        cnt++;
        for(int i=1;i<=n;i++)if((1ll<<j)&a[i])a[i]^=tmp ;
    }
    cout << (1ll<<cnt)-n ;
    return 0 ;
}
