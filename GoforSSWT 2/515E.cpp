#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
typedef long long ll ;
ll d[N],h[N];
ll powx[N],powy[N];
ll MIN=-10000000000000009;
struct Tree
{
    ll x,y,ans;
};
Tree st[N*4];
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]={powx[l],powy[l],0};
        return ;
    }
    construct(l,mid,m*2); construct(mid+1,r,m*2+1);
    ll p=max(st[m*2].ans,st[m*2+1].ans);
    st[m]={max(st[m*2].x,st[m*2+1].x),max(st[m*2].y,st[m*2+1].y),
        max(p,st[m*2].x+st[m*2+1].y)};
}
Tree findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)
    {
        return {MIN,MIN,0};
    }
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    Tree T1=findmax(l,mid,x,y,m*2),T2=findmax(mid+1,r,x,y,m*2+1);
    ll p=max(T1.ans,T2.ans);
    return {max(T1.x,T2.x),max(T1.y,T2.y),
        max(p,T1.x+T2.y)};
}
main()
{
    int n,m,i,j,l,r,dx,dy ;
    ll range=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%I64d",&d[i]);
    for(i=1;i<=n;i++)scanf("%I64d",&h[i]);
    for(i=1;i<=2*n-1;i++)
    {
        powx[i]=2*h[((i-1)%n)+1]-range;
        powy[i]=2*h[((i-1)%n)+1]+range;
        range+=d[((i-1)%n)+1];
    }
    construct(1,2*n-1,1);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        if(r==n)dx=1,dy=l-1;
        else if(l==1)dx=r+1,dy=n;
        else if(l>r)dx=r+1,dy=l-1;
        else dx=r+1,dy=n+l-1 ;
        printf("%I64d\n",findmax(1,2*n-1,dx,dy,1).ans);
    }
}
