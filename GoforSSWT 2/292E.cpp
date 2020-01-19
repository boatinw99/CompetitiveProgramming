#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N],b[N],lazy[N*4];
int st[N*4];
struct query
{
    int x,y,k;
};
query Q[N];
void update(int l,int r,int x,int y,int val,int m)
{
    int mid=l+r>>1 ;
    if(lazy[m])
    {
        st[m]=lazy[m];
        if(l<r)
        {
            lazy[m*2]=lazy[m*2+1]=lazy[m];
        }
        lazy[m]=0;
    }
    if(r<x||l>y)
    {
        return ;
    }
    if(l>=x&&r<=y)
    {
        st[m]=val;
        if(l!=r)
        {
            lazy[m*2]=lazy[m*2+1]=val;
        }
        return ;
    }
    update(l,mid,x,y,val,m*2); update(mid+1,r,x,y,val,m*2+1);
    st[m]=max(st[m*2],st[m*2+1]);
}
int findmax(int l,int r,int x,int m)
{
    int mid=l+r>>1;
    if(lazy[m])
    {
        st[m]=lazy[m];
        if(l<r)
        {
            lazy[m*2]=lazy[m*2+1]=lazy[m];
        }
        lazy[m]=0;
    }
    if(r<x||l>x)
    {
        return -1;
    }
    if(l==x&&r==x)
    {
        return st[m];
    }
    return max(findmax(l,mid,x,m*2),findmax(mid+1,r,x,m*2+1));
}
main()
{
    int n,m,i,j,t,l,r,z,p,q,e ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d %d %d",&Q[i].x,&Q[i].y,&Q[i].k);
            update(1,n,Q[i].y,(Q[i].y)+(Q[i].k)-1,i,1);
        }
        else
        {
            scanf("%d",&l);
            p=findmax(1,n,l,1);
            if(p==0)
            {
                printf("%d\n",b[l]);
            }
            else
            {
                ///p->query[i]; l-> pos b[i];
                q=Q[p].x; e=Q[p].y;
                printf("%d\n",a[l-e+q]);
            }
        }
    }
}
