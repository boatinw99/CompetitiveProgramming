#include<bits/stdc++.h>
using namespace std ;
int n,size;
int a[500009];
int st[500009];
void construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)st[m]=a[l];
	else 
	{
		construct(l,mid,m*2+1);
		construct(mid+1,r,m*2+2);
		st[m]=st[m*2+1]+st[m*2+2];
	}
}
int getsum(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(l>=x&&r<=y)return st[m];
	if(l>y||r<x)return 0;
	return getsum(l,mid,x,y,m*2+1)+getsum(mid+1,r,x,y,m*2+2);
}
void update(int l,int r,int x,int co,int m)
{
	int mid=(l+r)/2;
	if(x>r||x<l)return ;
	st[m]+=co;
	if(l==r)return ;
	update(l,mid,x,co,m*2+1);
	update(mid+1,r,x,co,m*2+2);
}
main()
{
	int i,x,y,m ;
	char c;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(size=1;size<n;size*=2); size=size*2-1;
	construct(0,n-1,0);
	for(i=0;i<size;i++)printf("%d ",st[i]);
	scanf("%d",&m);
	while(m--)
	{
		cin >> c;
		if(c=='a')//getsum
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",getsum(0,n-1,x,y,0));
		}
		if(c=='b')//update
		{
			scanf("%d %d",&x,&y);
			update(0,n-1,x,y-a[x],0);
			a[x]=y;
		}
	}
}
