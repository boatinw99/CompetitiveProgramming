#include<bits/stdc++.h>
using namespace std ;
int l=0,r= 2e9+7;
const int N = 500009;
int a[N];
main()
{
    int n,i,j,k,x;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    while(l+1<r)
    {
        int mid=(1ll*l+r)>>1;
        x=0;
        for(i=1;i<=n;i++)
        {
            x+=(a[i]-1)/mid+1;
        }
        if(x<=k)r=mid;
        else l=mid;
    }
    printf("%d",r);
}
