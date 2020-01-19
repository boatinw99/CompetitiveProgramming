#include<bits/stdc++.h>
using namespace std ;
int st[600009];
void update(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(r<x||l>x)return;
	if(l==r)
	{
		st[m]=y;	
		return;
	}
	update(l,mid,x,y,2*m+1);
	update(mid+1,r,x,y,2*m+2);
	st[m]=max(st[2*m+1],st[2*m+2]);
}
int find(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(l>=x&&r<=y)return st[m];
	if(l>y||r<x)return INT_MIN ;
	return max(find(l,mid,x,y,2*m+1),find(mid+1,r,x,y,2*m+2));
}
main()
{
	int n,i;	int m;
	scanf("%d %d",&n,&m);
	char c;
	int x,y ;
	while(m--)
	{
		scanf(" %c",&c);
		if(c=='U')
		{
			scanf("%d %d",&x,&y);
			x--;
			update(0,n-1,x,y,0);
		}
		else 
		{
			scanf("%d %d",&x,&y); x--;y--;
			printf("%d\n",find(0,n-1,x,y,0));
		}
	}
}
