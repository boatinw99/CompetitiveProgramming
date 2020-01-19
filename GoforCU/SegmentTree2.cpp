#include<bits/stdc++.h>
using namespace std ;
int a[500009];
int st[500009],n;
void construct(int l,int r,int m)
{
	int mid=(l+r)/2;
	if(l==r)st[m]=a[l];
	else 
	{
	    construct(l,mid,m*2+1);
		construct(mid+1,r,m*2+2);
		st[m]=min(st[m*2+1],st[m*2+2]);
	}
}
int find(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(l>=x&&r<=y)return st[m];
	if(r<x||l>y)return INT_MAX;
	return min(find(l,mid,x,y,m*2+1),find(mid+1,r,x,y,m*2+2));
}
void update(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(x>r||x<l)return ;
	if(l==r)
	{
		st[m]=y;
		return ;
	}
	update(l,mid,x,y,m*2+1);
	update(mid+1,r,x,y,m*2+2);
	st[m]=min(st[m*2+1],st[m*2+2]);
}
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	construct(0,n-1,0);
	int m,x,y ;
	scanf("%d",&m);
	while(m--)
	{
		char c;
		cin >> c;
		if(c=='a')
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",find(0,n-1,x,y,0));
		}
		else
		{
			scanf("%d %d",&x,&y);
			update(0,n-1,x,y,0);
		}
	}
}
