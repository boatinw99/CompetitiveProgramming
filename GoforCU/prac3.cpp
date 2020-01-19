#include<bits/stdc++.h>
using namespace std ;
int a[500009],n;
int st[500009];
int construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)st[m]=a[l];
	else st[m]=construct(l,mid,m*2+1)+construct(mid+1,r,m*2+2);
	return st[m];
}
int getsum(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(l>=x&&r<=y)return st[m];
	if(r<x||l>y)return 0;
	return getsum(l,mid,x,y,m*2+1)+getsum(mid+1,r,x,y,m*2+2);
}
void update(int l,int r,int x,int co,int m)
{
	int mid=(l+r)/2 ;
	if(x<l||x>r)return ;
	st[m]+=co;
	if(l==r)return ;
	update(l,mid,x,co,m*2+1);
	update(mid+1,r,x,co,m*2+2);
}
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	construct(0,n-1,0);
	printf("%d\n",getsum(0,n-1,1,3,0));
	update(0,n-1,1,10-a[1],0);
	printf("%d",getsum(0,n-1,1,3,0));
}
