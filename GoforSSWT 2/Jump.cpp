#include<bits/stdc++.h>
using namespace std ;
int l=-1,r=1e9;
const int N = 1e6+9;
int a[N];
main()
{
    int n,k,p,i,j,x,y,mid,co,min1=INT_MAX; ;
    scanf("%d %d %d",&n,&k,&p);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        min1=min(min1,a[i]);
    }
    while(l+1<r)
    {
        mid=l+r >> 1;
        co=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]>mid)
            {
                co++;
                i+=p-1;
            }
        }
        if(co<=k)
        {
            r=mid;
        }
        else l=mid;
    }
    printf("%d",(r>0)?r:min1);
}
