#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e6+9 ;
ll qs[N];
main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);
    ll min1=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }
    ll pr=-1e18;
    for(i=k;i<=n;i++)
    {
        min1=min(min1,qs[i-k]);
        pr=max(pr,qs[i]-min1);
    }
    printf("%lld",pr);
}
