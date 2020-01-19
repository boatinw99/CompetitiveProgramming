#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
struct Tree
{
    int maxl,maxr,sum,ans;
};
Tree st[N*4];
int a[N];
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m].maxl=st[m].maxr=st[m].ans=max(0,a[l]);
        st[m].sum=a[l];
        return ;
    }
    construct(l,mid,m*2+1);
    construct(mid+1,r,m*2+2);
    st[m].sum=st[m*2+1].sum+st[m*2+2].sum;
    st[m].ans=max(st[m*2+1].ans,st[m*2+2].ans);
    st[m].maxl=max(st[m*2+1].maxl,st[m*2+1].sum+st[m*2+2].maxl);
    st[m].maxr=max(st[m*2+2].maxr,st[m*2+2].sum+st[m*2+1].maxr);
    st[m].ans=max(st[m].ans,st[m].maxl);
    st[m].ans=max(st[m].ans,st[m].maxr);
    st[m].ans=max(st[m].ans,st[m*2+1].maxr+st[m*2+2].maxl);
}
Tree findans(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    struct Tree T;
    if(r<x||l>y)
    {
        T.sum=T.ans=T.maxl=T.maxr=0;
        return T ;
    }
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    Tree st1=findans(l,mid,x,y,m*2+1);
    Tree st2=findans(mid+1,r,x,y,m*2+2);
    T.sum=st1.sum+st2.sum;
    T.ans=max(st1.ans,st2.ans);
    T.maxl=max(st1.maxl,st1.sum+st2.maxl);
    T.maxr=max(st2.maxr,st2.sum+st1.maxr);
    T.ans=max(T.ans,max(T.maxl,T.maxr));
    T.ans=max(T.ans,st1.maxr+st2.maxl);
    return T;
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
        printf("%d\n",findans(0,n-1,l,r,0).ans);
    }
}
