#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 20;
int a[N],p=1;
int num[N];
ll ans=1;
main()
{
    ll S ;
    int b,i,x;
    scanf("%lld",&S);
    while(S)
    {
        a[p++]=S%10;
        S/=10;
    }
    for(i=0;i<10;i++)
    {
        num[i]=i+1;
    }
    for(i=10,x=9;i<=18;i++,x--)
    {
        num[i]=x;
    }
    for(i=1;i<p-1;i++)
    {
        scanf("%d",&b);
        x=a[i];
        if(b==1)
        {
            x+=10;
            a[i+1]--;
        }
        ans*=num[x];
    }
    if(b==0)ans*=num[a[p-1]];
    printf("%lld",ans);
}
