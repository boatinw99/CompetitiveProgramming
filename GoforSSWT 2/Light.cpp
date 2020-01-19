#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
struct Point
{
    int all,now;
};
Point st[N*4];
int a[N],dis[N],lazy[N*4],*p,key[N];
int z ;
void construct(int l,int r,int m)
{
    int mid=l+r >>1;
    if(l==r)
    {
        st[m].now=st[m].all=dis[l];
        return ;
    }
    construct(l,mid,m*2+1); construct(mid+1,r,m*2+2);
    st[m].all=st[m].now=st[m*2+1].all+st[m*2+2].all;
}
void update(int l,int r,int x,int m)
{
    int mid=l+r>>1;
    if(lazy[m])
    {
        st[m].now=st[m].all-st[m].now;
        if(l!=r)
        {
            lazy[m*2+1]=(lazy[m*2+1]+1)%2;
            lazy[m*2+2]=(lazy[m*2+2]+1)%2;
        }
        lazy[m]=0;
    }
    if(r<x||l>z)
    {
        return ;
    }
    if(l>=x&&r<=z)
    {
        st[m].now=st[m].all-st[m].now;
        if(l!=r)
        {
            lazy[m*2+1]=(lazy[m*2+1]+1)%2;
            lazy[m*2+2]=(lazy[m*2+2]+1)%2;
        }
        return ;
    }
    update(l,mid,x,m*2+1); update(mid+1,r,x,m*2+2);
    st[m].now=st[m*2+1].now+st[m*2+2].now;
}
main()
{
    int n,i,j,x,m ;
    scanf("%d %d",&n,&m);
    dis[0]=0;
    dis[m+1]=n;
    z=m;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        dis[i]=a[i];
    }
    sort(dis,dis+m+1);
    for(i=0;i<=m;i++)
    {
        key[i]=dis[i];
        dis[i]=dis[i+1]-dis[i];
    }
    construct(0,m,0);
    for(i=1;i<=m;i++)
    {
        x=a[i];
        p=lower_bound(key,key+m+1,x);
        update(0,m,p-key,0);
        printf("%d\n",st[0].now);
    }
}
