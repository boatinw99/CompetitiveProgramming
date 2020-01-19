#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
set<ll> s;
set<ll>::iterator it;
main()
{
    int n,i;
    ll x;
    int pr=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        s.insert(x);
    }
    it=s.end();
    it--;
    while(*it>1)
    {
        s.insert(*it/2);
        s.erase(it++);
        pr++;
        if(it==s.end())it--;
    }
    printf("%d",pr);
}
