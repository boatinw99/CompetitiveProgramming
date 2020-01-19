#include<bits/stdc++.h>
using namespace std ;
const int N = 209;
int st[N];
int a[N];
int lazy[N];
void construct(int l,int r,int m)
{
    int mid=(l+r)/2;
    if(l==r)
    {
        st[m]=a[l];
        return ;
    }
    construct(l,mid,m*2+1);
    construct(mid+1,r,m*2+2);
    st[m]=st[m*2+1]+st[m*2+2];
}
void update(int l,int r,int x,int y,int co,int m)
{
    int mid=(l+r)/2;
    if(lazy[m])
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l!=r)
        {
            lazy[m*2+1]+=lazy[m];
            lazy[m*2+2]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(r<x||l>y)
    {
        return ;
    }
    if(r<=y&&l>=x)
    {
        st[m]+=co*(r-l+1);
        if(l!=r)
        {
            lazy[m*2+1]+=co;
            lazy[m*2+2]+=co;
        }
        return ;
    }
    update(l,mid,x,y,co,m*2+1);
    update(mid+1,r,x,y,co,m*2+1);
    st[m]=st[m*2+1]+st[m*2+2];
}
int getsum(int l,int r,int x,int y,int m)
{
    int mid=(l+r)/2;
    if(lazy[m])
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l!=r)
        {
            lazy[m*2+1]+=lazy[m];
            lazy[m*2+2]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(r<=y&&l>=x)return st[m];
    if(r<x||l>y)return 0;
    return getsum(l,mid,x,y,m*2+1)+getsum(mid+1,r,x,y,m*2+2);
}
main()
{

}
