#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N],ans[N];
int st[N*4],lazy[N*4],n,m,bi[N];
vector<pair<int,int> > query;
int getval(int l,int r,int x,int m)
{
    int mid=l+r>>1;
    if(lazy[m]>=0)
    {
        st[m]=lazy[m];
        if(l<r)
        {
            lazy[m*2]=lazy[m];
            lazy[m*2+1]=lazy[m];
        }
        lazy[m]=-1;
    }
    if(r<x||l>x)
    {
        return -1;
    }
    if(l==x&&r==x)return st[m];
    return max(getval(l,mid,x,m*2),getval(mid+1,r,x,m*2+1));
}
void updateval(int i,int co)
{
    for(;i;i-=i&-i)bi[i]+=co;
}
int findvalue(int i)
{
    int sum=0;
    for(;i<N;i+=i&-i)sum+=bi[i];
    return sum;
}
void update(int l,int r,int x,int y,int co,int m)
{
    int mid=l+r>>1;
    if(lazy[m]>=0)
    {
        st[m]=lazy[m];
        if(l<r)
        {
            lazy[m*2]=lazy[m];
            lazy[m*2+1]=lazy[m];
        }
        lazy[m]=-1;
    }
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]=co;
        if(l<r)
        {
            lazy[m*2]=co;
            lazy[m*2+1]=co;
        }
        return ;
    }
    update(l,mid,x,y,co,m*2);
    update(mid+1,r,x,y,co,m*2+1);
    st[m]=max(st[m*2],st[m*2+1]);
}
int bsearch(int x)
{
    int l=0,r=m+1,y;
    while(l+1<r)
    {
         int mid=l+r>>1;
         y=query[mid].first;
         if(y+getval(1,m,mid,1)>=x)
         {
             //printf("aaa %d->%d\n",mid,getval(1,m,mid,1));
             r=mid;
         }
         else l=mid;
    }
    //printf("return %d\n",r);
    return r;
}
main()
{
    int i,j,x ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        query.push_back({x,i});
    }
    query.push_back({0,0});
    lazy[1]=a[1];
    sort(query.begin(),query.end());
    for(i=2;i<=n;i++)
    {
        x=bsearch(a[i]);
        if(x<=m)
        {
            update(1,m,x,m,a[i],1);
            updateval(x-1,1);
        }
    }
    for(i=1;i<=m;i++)
    {
        x=findvalue(i);
        ans[query[i].second]=x;
    }
    for(i=1;i<=m;i++)printf("%d\n",ans[i]);
}
