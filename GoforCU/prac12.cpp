///LazyProp
#include<bits/stdc++.h>
using namespace std ;
const int N = 109;
int st[N];
int lazy[N];
int a[5]={1,2,3,4,5};
void construct(int l,int r,int m)
{
    int mid=(l+r)/2 ;
    if(l==r)
    {
        st[m]=a[l];
        return ;
    }
    construct(l,mid,m*2+1);
    construct(mid+1,r,m*2+2);
    st[m]=st[m*2+1]+st[m*2+2];
}
int getsum(int l,int r,int x,int y,int m)
{
    int mid=(l+r)/2;
    if(lazy[m])
    {
        st[m]+=(r-l+1)*lazy[m];
        if(l!=r)
        {
            lazy[m*2+1]+=lazy[m];
            lazy[m*2+2]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    if(l>y||r<x)return 0;
    return getsum(l,mid,x,y,m*2+1)+getsum(mid+1,r,x,y,m*2+2);
}
void update(int l,int r,int x,int y,int co,int m)
{
    int mid=(l+r)/2;
    if(lazy[m])
    {
        st[m]+=(r-l+1)*lazy[m];
        if(l!=r)
        {
            lazy[m*2+1]+=lazy[m];
            lazy[m*2+2]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(l>y||r<x|l>r)
    {
        return ;
    }
    if(l>=x&&r<=y)
    {
        st[m]+=co*(r-l+1) ;
        if(l!=r)
        {
            lazy[m*2+1]+=co;
            lazy[m*2+2]+=co;
        }
        return ;
    }
    update(l,mid,x,y,co,m*2+1);
    update(mid+1,r,x,y,co,m*2+2);
    st[m]=st[m*2+1]+st[m*2+2];
}
main()

{
    int m,n=5;
    construct(0,n-1,0);
    update(0,n-1,0,3,1,0);
    printf("%d",getsum(0,n-1,2,4,0));

}
