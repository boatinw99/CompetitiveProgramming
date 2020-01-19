#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
float val[N];
int co=0;
int divide(int l,int r)
{
    int mid=l+r>>1,i;
    int x=1,k,p1,p2;
    printf("%d %d|%d\n",l,r,x);
    if(l==r);
    else if((r-l+1)%2==0)
    {
        x*=divide(l,mid);
        x*=divide(mid+1,r);
    }
    else
    {
        p1=divide(l,mid); p2=divide(mid+1,r);
        x=p1*p2;
        p1=divide(l,mid-1); p2=divide(mid,r);
        x+=p1*p2;
        co++;
    }
    for(i=l;i<=r;i++)val[i]+=x*(r-l+1);
    return x;
}
main()
{
    int n,i ;
    float f;
    scanf("%d",&n);
    divide(1,n);
    co++;
    for(i=1;i<=n;i++)
    {
        f=val[i]/co;
        printf("%f ",val[i]);
    }
}
