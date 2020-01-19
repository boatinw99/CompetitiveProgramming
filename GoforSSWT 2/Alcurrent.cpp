#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+8;
int a[N+1];
ll l[N+1],r[N+1];
// from left and from right
main()
{
    int n,i,k,j,in ;
    ll x,y ;
    ll pr=1e18;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&in);
        a[in]++;
    }
    x=0;
    for(i=1;i<=N;i++)
    {
        l[i]=l[i-1]+x;
        x+=a[i];
    }
    x=0;
    for(i=N;i>0;i--)
    {
        r[i]=r[i+1]+x;
        x+=a[i];
    }
    y=1;
    for(i=1;i<=N&&y>0;i++)
    {
        j=min(i+k,N-1);
        x=l[i];
        y=r[j];
        if(x==y)
        {
            pr=min(pr,x);
        }
        else if(x<y)
        {
            if(l[j]+x>=y)
            {
                pr=min(pr,y);
            }
        }
        else
        {
            if(r[i]+y>=x)
            {
                pr=min(pr,x);
            }
        }
    }
    printf("%lld",pr);
}
