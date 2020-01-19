#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
set<ll> s;
ll pr=0 ;
void dfs(ll i)
{
    if(i==1)return ;
    if(s.find(i)==s.end())
    {
        pr++;
        s.insert(i);
        dfs(i/2);
    }
}
main()
{
    ll m,x ;
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld",&x);
        dfs(x);
    }
    printf("%lld",pr);
}
