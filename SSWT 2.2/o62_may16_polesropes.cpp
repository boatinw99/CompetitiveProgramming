#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 ;
int n,m,x,y ;
int lazy[N<<2],st[N<<2];
inline void push(int l,int r,int m)
{
    if(lazy[m]==-1||l>r)return ;
    st[m]=0;
    if(l<r)
    {
        lazy[m<<1]=lazy[m<<1|1]=0;
    }
    lazy[m]=-1;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=10;
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
inline void set0(int l,int r,int m)
{
    push(l,r,m);
    if(r<x||l>y||l>r)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]=0;
        push(l,r,m);
        return ;
    }
    set0(l,mid,m<<1);
    set0(mid+1,r,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
inline void update(int l,int r,int m)
{
    push(l,r,m);
    if(r<x||l>x||l>r)return ;
    if(l==r)
    {
        st[m]+=y;
        return ;
    }
    update(l,mid,m<<1);
    update(mid+1,r,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
inline int getsum(int l,int r,int m)
{
    push(l,r,m);
    if(st[m]==0)return 0 ;
    if(r<x||l>y||l>r)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,m<<1)+getsum(mid+1,r,m<<1|1);
}
void updl(int u,int cst)
{
    int l = 1,r=u ;
    int sum ;
    while(l+1<r)
    {
        x=mid,y=u-1;
        sum = getsum(1,n,1);
        if(sum>=cst)l=mid;
        else r=mid;
    }
    if(r<u)
    {
        x=r,y=u-1;
        sum = getsum(1,n,1);
        set0(1,n,1);
        cst-=sum;
    }
    x=l,y=-cst;
    update(1,n,1);
}
void updr(int u,int cst)///update [u+1,n];
{
    int l=u,r=n;
    while(l<r)
    {
        x=u+1,y=mid;
        int sum = getsum(1,n,1);
        if(sum>=cst)r=mid;
        else l=mid+1 ;
    }
    if(l>u)
    {
        x=u+1,y=l;
        int sum = getsum(1,n,1);
        set0(1,n,1);
        cst-=sum;
    }
    x=r,y=-cst;
    update(1,n,1);
}
void query(int u,int cst)
{
    x=1,y=u-1;
    int suml = getsum(1,n,1) ;
    x=u+1,y=n;
    int sumr = getsum(1,n,1);
    x=u,y=cst;
    update(1,n,1);
    if(suml<cst/2)
    {
        x=1,y=u-1;
        set0(1,n,1);
        cst-=suml;
        updr(u,cst);
        return ;
    }
    else if(sumr<cst/2)
    {
        x=u+1,y=n;
        set0(1,n,1);
        cst-=sumr;
        updl(u,cst);
        return ;
    }
    else
    {
        cst/=2;
        updl(u,cst);
        updr(u,cst);
        return ;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    n--;
    memset(lazy,-1,sizeof lazy);
    construct(1,n,1);
    while(m--)
    {
        int typ,u,v ;
        cin >> typ >> u ;
        if(typ==2)
        {
            x=u,y=u;
            cout << getsum(1,n,1) << '\n' ;
        }
        else
        {
            cin >> v ;
            query(u,v);
        }
    }
    return 0 ;
}
