#include<bits/stdc++.h>
using namespace std ;
const int M=100009;
int a[M],st[M],lazy[M];
void construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)
	{
		st[m]=a[l];
		return ;
	}
	construct(l,mid,2*m+1); construct(mid+1,r,2*m+2);
	st[m]=min(st[m*2+1],st[m*2+2]);
}
int find(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(lazy[m])
	{
		st[m]+=lazy[m]*(r-l+1);
		if(l!=r)
		{
			st[m*2+1]+=lazy[m];
			st[m*2+2]+=lazy[m];	
		}
		lazy[m]=0;
	}
	if(r<x||l>y)return INT_MAX;
	if(l>=x&&r<=y)return st[m];
	return min(find(l,mid,x,y,m*2+1),find(mid+1,r,x,y,m*2+2));
}
void update(int l,int r,int x,int y,int co,int m)
{
	int mid=(l+r)/2;
	if(lazy[m])
	{
		st[m]+=lazy[m]*(r-l+1);
		if(l!=r)
		{
			st[m*2+1]+=lazy[m];
			st[m*2+2]+=lazy[m];
		}
		lazy[m]=0;
	}
	if(r<x||l>y)return ;
	if(l>=x&&r<=y)
	{
		st[m]+=co*(r-l+1);
		if(l!=r)
		{
			lazy[2*m+1]+=co;
			lazy[2*m+2]+=co;
		}
		return ;
	}
	update(l,mid,x,y,co,m*2+1);
	update(mid+1,r,x,y,co,m*2+2);
	st[m]=min(st[m*2+1],st[m*2+2]);
	
}
main()
{
	int n,i,x,y ;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	construct(0,n-1,0);
	printf("%d\n",find(0,n-1,1,3,0));
	update(0,n-1,1,5,10,0);
	printf("%d\n",find(0,n-1,1,3,0));
	update(0,n-1,1,3,2,0);
	printf("%d\n",find(0,n-1,1,3,0));
}
