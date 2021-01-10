#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
main()
{
    ll n,m,a,b ;
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&a,&b);
    ll max1=min((n%m)*b,(m-(n%m))*a);
    printf("%I64d",max1);
}
