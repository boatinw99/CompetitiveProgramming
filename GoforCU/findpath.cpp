#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
set<ll> s;
main()
{
    int m;
    ll x;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%lld",&x);
        s.insert(x);
    }
    int pr=0;
    ll y;
    s.insert(0);
    while((x=*s.rbegin())>1)
    {
        s.erase(x);
        y=*s.rbegin();
        while(x>y&&x>1)
        {
            pr++;
            x/=2;
        }
        s.insert(x);
    }
    printf("%d",pr);
}
