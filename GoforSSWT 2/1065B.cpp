#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
main()
{
    ll i,j ;
    ll n,m,min1,max1,k ;
    scanf("%I64d %I64d",&n,&m);
    min1=max(1ll*0,n-2*m);
    printf("%I64d ",min1);
    for(i=0;i<=n;i++)
    {
        if(i*(i-1)/2>=m)
        {
            k=i;
            printf("%I64d",n-k);
            break;
        }
    }
}
