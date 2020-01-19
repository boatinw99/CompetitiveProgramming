#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
main()
{
    ll n,m,x,sum ;
    scanf("%lld %lld",&n,&m);
    ll l = m-1 , r = n+1;
    while(l+1<r)
    {
        ll mid=l+r>>1;
        x= mid ;
        sum = 0;
        while(x>0)
        {
            sum+=x%10;
            x/=10;
        }
        if(mid-sum>=m)
        {
            r=mid;
        }
        else l=mid;
    }
    if(r<=n)
    {
        printf("%lld\n%lld",n-r+1,n);
    }
    else
    {
        printf("0\n-1");
    }
}
