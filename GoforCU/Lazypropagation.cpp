#include<bits/stdc++.h>
using namespace std ;
int a[5000];
int st[500];
int lazy[500];
void construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)
	{
		st[m]=a[l];
		return;
	}
	construct(l,mid,2*m+1); construct(mid+1,r,2*m+2);
	st[m]=st[2*m+1]+st[2*m+2];
}
int getsum(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(lazy[m])
	{
		st[m]+=lazy[m]*(r-l+1);
		if(l!=r)
		{
			lazy[2*m+1]+=lazy[m];
			lazy[2*m+2]+=lazy[m];
		}
		lazy[m]=0;
	}
	if(r<x||l>y)
	{
		return 0;
	}
	if(l>=x&&r<=y)return st[m];
	return getsum(l,mid,x,y,2*m+1)+getsum(mid+1,r,x,y,2*m+2);
}
void update(int l,int r,int x,int y,int co,int m)
{
	int mid=(l+r)/2;
	if(lazy[m])
	{
		st[m]+=lazy[m]*(r-l+1);
		if(l!=r)
		{
			lazy[2*m+1]=lazy[m];
			lazy[2*m+2]=lazy[m];
		}
		lazy[m]=0;
	}
	if(l>r||r<x||l>y)return;
	if(l>=x&&r<=y)
	{
		st[m]+=(r-l+1)*co;
		if(l!=r)
		{
			lazy[2*m+1]+=co;
			lazy[2*m+2]+=co;
		}
		return ;
	}
	update(l,mid,x,y,co,2*m+1); update(mid+1,r,x,y,co,2*m+2);
	st[m]=st[m*2+1]+st[m*2+2];
}
main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	construct(0,n-1,0);
	printf("%d\n",getsum(0,n-1,2,4,0));
	update(0,n-1,0,3,1,0);
	printf("%d\n",getsum(0,n-1,2,4,0));
	//update(0,n-1,1,3,2,0);
	printf("%d\n",getsum(0,n-1,2,4,0));
}
