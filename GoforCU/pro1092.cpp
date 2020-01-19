#include<bits/stdc++.h>
using namespace std ;
int s[100009];
int parent[100009];
int find(int i)
{
	if(parent[i]!=i)
	{
		parent[i]=find(parent[i]);
	}
	return parent[i];	
}
int unionset(int x,int y)
{
	int pax=find(x),pay=find(y);
	if(pax==pay)
	{
		printf("-1\n");
	}
	else if(s[pax]<s[pay]||(s[pax]==s[pay]&&pay<pax))
	{
		printf("%d\n",pay);
		s[pay]+=s[pax]/2;
		parent[pax]=parent[pay];
	}
	else 
	{
		printf("%d\n",pax);
		s[pax]+=s[pay]/2;
		parent[pay]=parent[pax];
	}
}
main()
{
	int i,m,x,y,n ;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		parent[i]=i;
	}
	while(m--)
	{
		scanf("%d %d",&x,&y);
		unionset(x,y);
	}
}
