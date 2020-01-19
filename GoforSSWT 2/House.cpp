#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
struct Tree
{
    int ml,mr,sum,MAX ;
};
int a[N];
struct Tree st[N*4];
void construct(int l,int r,int m)
{
    int mid= l+r >> 1;
    if(l==r)
    {
        st[m].sum=a[l];
        st[m].ml=max(a[l],0);
        st[m].mr=st[m].ml;
        st[m].MAX=max(a[l],0);
        return ;
    }
    construct(l,mid,m*2+1);
    construct(mid+1,r,m*2+2);
    st[m].sum=st[m*2+1].sum+st[m*2+2].sum;
    st[m].MAX=max(st[m*2+1].MAX,st[m*2+2].MAX);
    st[m].ml=max(st[m*2+1].ml,st[m*2+1].sum+st[m*2+2].ml);
    st[m].mr=max(st[m*2+2].mr,st[m*2+2].sum+st[m*2+1].mr);
    st[m].MAX=max(st[m].MAX,st[m].ml);
    st[m].MAX=max(st[m].MAX,st[m].mr);
    st[m].MAX=max(st[m].MAX,st[m*2+1].mr+st[m*2+2].ml);
}
struct Tree findmax(int l,int r,int x,int y,int m)
{
    int mid= l+r >> 1;
    struct Tree Tl,Tr,T ;
    if(l>y||r<x)
    {
        T.sum=T.MAX=T.ml=T.mr=0;
        return T ;
    }
    if(l>=x&&r<=y)
    {
        T=st[m];
        return T ;
    }
    Tl=findmax(l,mid,x,y,m*2+1);
    Tr=findmax(mid+1,r,x,y,m*2+2);
    T.sum=Tl.sum+Tr.sum;
    T.MAX=max(Tl.MAX,Tr.MAX);
    T.ml=max(Tl.ml,Tl.sum+Tr.ml);
    T.mr=max(Tr.mr,Tr.sum+Tl.mr);
    T.MAX=max(T.MAX,T.ml);
    T.MAX=max(T.MAX,T.mr);
    T.MAX=max(T.MAX,Tl.mr+Tr.ml);
    return T ;
}
main()
{
    int n,m,i,j,l,r ;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    construct(0,n-1,0);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",findmax(0,n-1,l,r,0).MAX);
    }
}
