#include<bits/stdc++.h>
using namespace std ;
const int N = 59;
int st[N];
int a[N];
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
    st[m]+=st[m*2+1]+st[m*2+2];
}
int sum(int l,int r,int x,int y,int m)
{
    int mid=(l+r)/2;
    if(r<x||l>y)
    {
        return 0;
    }
    if(r<=y&&l>=x)
    {
        return st[m];
    }
    return sum(l,mid,x,y,m*2+1)+sum(mid+1,r,x,y,m*2+2);
}
void update(int l,int r,int x,int co,int m)
{
    int mid=(l+r)/2;
    if(r<x||l>x)return ;
    st[m]+=co;
    if(l==r)
    {
        return ;
    }
    update(l,mid,x,co,m*2+1);
    update(mid+1,r,x,co,m*2+2);
    st[m]=st[m*2+1]+st[m*2+2];
}
main()
{

}
