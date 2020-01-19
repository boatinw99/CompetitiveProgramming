#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int stmin[N*4],stmax[N*4];
int a[N];
void constructmin(int l,int r,int m)
{
    int mid=l+r >> 1;
    if(l==r)
    {
        stmin[m]=a[l];
        return ;
    }
    constructmin(l,mid,m*2+1);
    constructmin(mid+1,r,m*2+2);
    stmin[m]=min(stmin[m*2+1],stmin[m*2+2]);
}
void constructmax(int l,int r,int m)
{
    int mid=l+r >> 1;
    if(l==r)
    {
        stmax[m]=a[l];
        return ;
    }
    constructmax(l,mid,m*2+1);
    constructmax(mid+1,r,m*2+2);
    stmax[m]=max(stmax[m*2+1],stmax[m*2+2]);
}
void updatemin(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1;
    if(r<x||l>x)
    {
        return ;
    }
    if(l==x&&r==x)
    {
        stmin[m]=y;
        return ;
    }
    updatemin(l,mid,x,y,m*2+1);
    updatemin(mid+1,r,x,y,m*2+2);
    stmin[m]=min(stmin[m*2+1],stmin[m*2+2]);
}
void updatemax(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1;
    if(r<x||l>x)
    {
        return ;
    }
    if(l==x&&r==x)
    {
        stmax[m]=y;
        return ;
    }
    updatemax(l,mid,x,y,m*2+1);
    updatemax(mid+1,r,x,y,m*2+2);
    stmax[m]=max(stmax[m*2+1],stmax[m*2+2]);
}
int findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1;
    if(r<=y&&l>=x)return stmin[m];
    if(r<x||l>y)return INT_MAX ;
    return min(findmin(l,mid,x,y,m*2+1),findmin(mid+1,r,x,y,m*2+2));
}
int findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1;
    if(r<=y&&l>=x)return stmax[m];
    if(r<x||l>y)return INT_MIN ;
    return max(findmax(l,mid,x,y,m*2+1),findmax(mid+1,r,x,y,m*2+2));
}
main()
{
    int n,i,j,l,r ;
    char c;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    constructmin(0,n-1,0);
    constructmax(0,n-1,0);
    while(cin >> c >> l >> r)
    {
        if(c=='U')
        {
            updatemin(0,n-1,l,r,0);
            updatemax(0,n-1,l,r,0);
        }
        else
        {
            printf("%d %d\n",findmin(0,n-1,l,r,0),findmax(0,n-1,l,r,0));
        }
    }
}
