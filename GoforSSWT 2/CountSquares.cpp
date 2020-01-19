#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e9+7;
main()
{
    long long ans = 0 ;
    int n,m,len ;
    scanf("%d %d",&n,&m);
    for(len=1;len<=min(n,m);len++)
    {
        ans+=1ll*len*(n-len+1)*(m-len+1);
        ans%=MOD;
    }
    printf("%lld",ans);
}
