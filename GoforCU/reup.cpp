#include<bits/stdc++.h>
using namespace std ;
queue<pair<pair<int,int>,int> > q;
const int N = 1e5+9;
int qs[N];
int st[2*N];
void construct(int l,int r,int m)
{
    int mid=(l+r)/2 ;
    if(l==r)
    {
        st[m]=qs[l];
    }
    else
    {
        construct(l,mid,2*m);
        construct(mid+1,r,2*m+1);
        st[m]=max(st[m*2],st[m*2+1]);
    }
}
int query(int l,int r,int x,int y,int m)
{
    int mid=(l+r)/2;
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    if(l>y||r<x)return INT_MIN ;
    return max(query(l,mid,x,y,m*2),query(mid+1,r,x,y,m*2+1));
}
main()
{
    int n,m,x,y,i,j,l,r ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        qs[l]+=x;
        qs[r+1]-=x;
        q.push({{l,r},x});
    }
    for(i=1;i<=n;i++)qs[i]+=qs[i-1];
    construct(1,n,1);
    int min1=INT_MAX ;
    int u,v,s ;
    while(!q.empty())
    {
        l=q.front().first.first;
        r=q.front().first.second ;
        x=q.front().second;
        u=0; v=0;
        s=query(1,n,l,r,1);
        if(l>1)u=query(1,n,1,l-1,1);
        if(r<n)v=query(1,n,r+1,n,1);
        int T=max(u,v);
        T=max(T,s-x);
        min1=min(min1,T);
        q.pop();
    }
    printf("%d ",min1);
}
