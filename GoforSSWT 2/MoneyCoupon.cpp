#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
main()
{
    ll sum = 0 ,sub = 0 , mul = 1 ,x  ;
    bool b = 0;
    int m ;
    char c;
    scanf("%d",&m);
    while(m--)
    {
        scanf(" %c",&c);
        scanf("%lld",&x);
        if(c=='+')sum+=x;
        else if(c=='-')sub+=x;
        else
        {
            if(x==0)b++;
            else mul*=x;
        }
    }
    if(b==1)sub=0;
    printf("%lld",sum*mul-sub);
}
