#include<bits/stdc++.h>
using namespace std ;
const int M=500009;
bool st[M],lazy[M];
void update(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2; 
	if(lazy[m])
	{
		st[m]=(r-l+1)-st[m];
		if(l!=r)
		{
			lazy[m*2+1]=1-lazy[m*2+1];
			lazy[m*2+2]=1-lazy[m*2+2];
		}
		lazy[m]=0;
	}
	if(r<x||l>y)return ;
	if(l>=x&&r<=y)
	{
		st[m]=(r-l+1)-st[m];
		if(l!=r)
		{
			lazy[m*2+1]=1-lazy[m*2+1];
			lazy[m*2+2]=1-lazy[m*2+2];
		}
		return ;
	}
	update(l,mid,x,y,m*2+1); update(mid+1,r,x,y,m*2+2);
	st[m]=st[m*2+1]+st[m*2+2];
}
int getsum(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(lazy[m])
	{
		st[m]=(r-l+1)-st[m];
		if(l!=r)
		{
			lazy[m*2+1]=1-lazy[m*2+1];
			lazy[m*2+2]=1-lazy[m*2+2];
		}
		lazy[m]=0;
	}
	if(r<x||l>y)return 0;
	if(l>=x&&r<=y)
	{
		return st[m];
	}
	return getsum(l,mid,x,y,m*2+1)+getsum(mid+1,r,x,y,m*2+2);
}
main()
{
	int n,m;
	scanf("%d",&n);
	char c;	int x , y;
	cout << getsum(0,n-1,0,3,0) << '\n' ;
	update(0,n-1,1,2,0);
	cout << getsum(0,n-1,0,1,0) << '\n';
	update(0,n-1,0,3,0);
	cout << getsum(0,n-1,0,3,0) << '\n' ;
	
}
