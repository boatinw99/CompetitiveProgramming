#include "wall.h"
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e6+9 ,inf = 2e9;
int st[N<<2],ans[N];
pii lazy[N<<2];
void operate(pii &a,pii b)
{
    if(b.se<=a.fi)
    {
        a={b.se,b.se};
    }
    else if(a.se<=b.fi)
    {
        a={b.fi,b.fi};
    }
    else
    {
        a.fi=max(a.fi,b.fi);
        a.se=min(a.se,b.se);
    }
}
void push(int l,int r,int m)
{
    ///fi -> min ||| se -> max
    if(lazy[m].fi==-inf&&lazy[m].se==inf)return ;
    st[m]=max(st[m],lazy[m].fi);
    st[m]=min(st[m],lazy[m].se);
    if(l<r)
    {
        operate(lazy[m<<1],lazy[m]);
        operate(lazy[m<<1|1],lazy[m]);
    }
    lazy[m]={-inf,inf};
}
void update(int l,int r,int x,int y,pii nw,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]=nw;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,nw,m<<1);
    update(mid+1,r,x,y,nw,m<<1|1);
}
void getans(int l,int r,int m)
{
    push(l,r,m);
    if(l==r)
    {
        ans[l]=st[m];
        return ;
    }
    getans(l,mid,m<<1);
    getans(mid+1,r,m<<1|1);
}
void buildWall(int n,int k,int op[],int left[],
               int right[],int height[],int finalHeight[])
{
    for(int i=0;i<N*4;i++)lazy[i]={-inf,inf};
    for(int i=0;i<k;i++)
    {
        int l = left[i] , r = right[i] ;
        if(op[i]==1)update(0,n-1,l,r,{height[i],inf},1);
        else update(0,n-1,l,r,{-inf,height[i]},1);
    }
    getans(0,n-1,1);
    for(int i=0;i<n;i++)finalHeight[i]=ans[i];
    return ;
}

