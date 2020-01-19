#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
int A[4]={2,3,11,13};
main()
{
    int i,j ;
    ll n,ans=0;
    int bits=1<<4,mul,cnt ;
    scanf("%lld",&n);
    for(i=1;i<bits;i++)
    {
        cnt = 0; mul=1 ;
        for(j=0;j<4;j++)
        {
            if((1<<j)&i)mul*=A[j],cnt++;
        }
        if(cnt&1)ans+=n/mul;
        else ans-=n/mul;
    }
    printf("%lld %lld",ans/__gcd(ans,n),n/__gcd(ans,n));
}
