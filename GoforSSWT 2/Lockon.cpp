#include<bits/stdc++.h>
using namespace std ;
main()
{
    int l=0,r=1e6,n,k,x,y;
    scanf("%d %d",&n,&k);
    while(n--)
    {
        scanf("%d %d",&x,&y);
        if(x>y)
        swap(x,y);
        l=max(l,x);
        r=min(r,y);
    }
    if(l>r)printf("-1");
    else if(l<=k&&k<=r)printf("0");
    else if(k<l)
    {
        printf("%d",l-k);
    }
    else if(k>r)
    {
        printf("%d",k-r);
    }
}
