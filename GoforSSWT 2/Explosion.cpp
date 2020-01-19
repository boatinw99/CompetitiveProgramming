#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
struct Point
{
    int pos ;
    int ri;
    int index ;
};
Point a[N],*p;
int dpl[N];
bool comparepos(Point x,Point y)
{
    return x.pos < y.pos ;
}
bool comparel(Point x,const int Val )
{
    return x.pos < Val;
}
int stmin[N*4],stmax[N*4];
int findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1 ;
    if(l>=x&&r<=y)
    {
        return stmax[m];
    }
    if(r<x||l>y)
    {
        return 0 ;
    }
    return max(findmax(l,mid,x,y,m*2),findmax(mid+1,r,x,y,m*2+1));
}
void updatemax(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1 ;
    if(r<x||l>x)
    {
        return ;
    }
    if(l==r)
    {
        stmax[m]=y;
        return ;
    }
    updatemax(l,mid,x,y,m*2); updatemax(mid+1,r,x,y,m*2+1);
    stmax[m]=max(stmax[m*2],stmax[m*2+1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1 ;
    if(l>=x&&r<=y)
    {
        return stmin[m];
    }
    if(r<x||l>y)
    {
        return INT_MAX ;
    }
    return min(findmin(l,mid,x,y,m*2),findmin(mid+1,r,x,y,m*2+1));
}
void updatemin(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1 ;
    if(r<x||l>x)
    {
        return ;
    }
    if(l==r)
    {
        stmin[m]=y;
        return ;
    }
    updatemin(l,mid,x,y,m*2); updatemin(mid+1,r,x,y,m*2+1);
    stmin[m]=min(stmin[m*2],stmin[m*2+1]);
}
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a[i].index=i ;
        scanf("%d",&a[i].pos);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i].ri);
    }
    sort(a+1,a+1+n,comparepos);
    cout << '\n';
    ///RRRR
    int x,max1,min1,val;
    for(i=n;i>0;i--)
    {
        p=lower_bound(a+i,a+1+n,a[i].pos+a[i].ri+1,comparel);
        p--;
        x= p-a ;
        max1=findmax(1,n,i,x,1);
        if(max1==0)val=i; else val = max1;
        updatemax(1,n,i,val,1);
    }
    int ans=0,in;
    for(i=1;i<=n;i++)
    {
        p=lower_bound(a+1,a+1+i,a[i].pos-a[i].ri,comparel);
        x=p-a;
        if(x==i)
        {
            val=i;
        }
        else
        {
            min1=findmin(1,n,x,i-1,1);
            val=min1;
        }
        updatemin(1,n,i,val,1);
        max1=findmax(1,n,val,i,1);
       // printf("%d %d\n",val,max1);
        if(max1-val+1>ans)
        {
            ans=max1-val+1; in=a[i].index;
        }
        else if(max1-val+1==ans)
        {
            in=min(a[i].index,in);
        }
    }
    printf("%d %d",in,ans);
}
