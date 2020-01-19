#include<bits/stdc++.h>
using namespace std ;
int st[1000009];
void update(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(x<l||x>r)return ;
	if(l==r)
	{
		st[m]=y; return; 
	}
	update(l,mid,x,y,m*2+1);
	update(mid+1,r,x,y,m*2+2);
	st[m]=max(st[m*2+1],st[m*2+2]);
}
int find(int l,int r,int x,int y,int m)
{
	int mid=(l+r)/2;
	if(x<=l&&y>=r)return st[m];
	if(r<x||l>y)return INT_MIN;
	return max(find(l,mid,x,y,2*m+1),find(mid+1,r,x,y,2*m+2));
}
main()
{
	int n,m,x,y ;
	char c;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf(" %c",&c);
		if(c=='U')
		{
			scanf("%d %d",&x,&y); 
			x--;
			update(0,n-1,x,y,0);	
		}
		else if(c=='P')	
		{
			scanf("%d %d",&x,&y); 
			x--; y--;
			printf("%d\n",find(0,n-1,x,y,0));
		}	
	}
}
