//Lazy
#include<bits/stdc++.h>
using namespace std ;
int a[109];
int st[109];
int lazy[109];
void construct(int l,int r,int m)
{
    int mid=(l+r)/2;
    if(l==r)st[m]=a[l];
    else
    {
        construct(l,mid,m*2+1);
        construct(mid+1,r,m*2+2);
        st[m]=st[m*2+1]+st[m*2+2];
    }
}
void update(int l,int r,int m,int x,int y,int val)
{
    int mid=(l+r)/2 ;
    if(lazy[m]>0)
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l!=r)
        lazy[m*2+1]+=lazy[m],lazy[m*2+2]+=lazy[m];
        lazy[m]=0;
    }
    if(l>y||r<x)return ;
    if(r<=y&&l>=x)
    {
        st[m]+=(r-l+1)*val;
        lazy[m*2+1]=val;
        lazy[m*2+2]=val;
        return ;
    }
    update(l,mid,m*2+1,x,y,val);
    update(mid+1,r,m*2+2,x,y,val);
    st[m]=st[m*2+1]+st[m*2+2];
}
int sum(int l,int r,int x,int y,int m)
{
    int mid=(l+r)/2 ;
    if(lazy[m])
    {
        st[m]+=(r-l+1)*lazy[m];
        lazy[m*2+1]+=lazy[m];
        lazy[m*2+2]+=lazy[m];
        lazy[m]=0;
    }
    if(r<x||l>y)return 0;
    if(r<=y&&l>=x)return st[m];
    return sum(l,mid,x,y,m*2+1)+sum(mid+1,r,x,y,m*2+2);
}
main()
{
    int n=4;
    construct(0,n-1,0);
    update(0,n-1,0,1,3,1);
    update(0,n-1,0,0,2,2);
    update(0,n-1,0,0,0,3);
    printf("%d",sum(0,n-1,0,3,0));
}
