//Lazy query MAX
#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;;
int a[N];
int st[N*4];
int lazy[N*4];
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]=a[l];
        return ;
    }
    construct(l,mid,m*2+1);
    construct(mid+1,r,m*2+2);
    st[m]=max(st[m*2+1],st[m*2+2]);
}
void update(int l,int r,int x,int y,int co ,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)
    {
        return ;
    }
    if(lazy[m])
    {
        st[m]+=lazy[m];
        if(l<r)
        {
            lazy[m*2+1]+=lazy[m];
            lazy[m*2+2]+=lazy[m];
        }
        lazy[m]=0;
    }

    if(r<=y&&l>=x)
    {
        st[m]+=co;
        if(l!=r)
        {
            lazy[m*2+1]+=co ;
            lazy[m*2+2]+=co ;
        }
        return ;
    }
    update(l,mid,x,y,co,m*2+1);
    update(mid+1,r,x,y,co,m*2+2);
    st[m]=max(st[m*2+1],st[m*2+2]);
}
int findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)
    {
        return INT_MIN ;
    }
    if(lazy[m])
    {
        st[m]+=lazy[m];
        if(l!=r)
        {
            lazy[m*2+1]+=lazy[m];
            lazy[m*2+2]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(r<=y&&l>=x)
    {
        return st[m];
    }
    return max(findmax(l,mid,x,y,m*2+1),findmax(mid+1,r,x,y,m*2+2));
}
main()
{
    for(int i = 0; i < N; i++) a[i] = 1;
    construct(0,N-1,0);
    update(0,N-1,0,6,5,0);
    update(0,N-1,7,10,12,0);
    update(0,N-1,10,N-1,100,0);
    cout << findmax(0,N-1,0,N-1,0);
}
