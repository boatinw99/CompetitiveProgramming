#include<bits/stdc++.h>
using namespace std ;
int find(int x)
{
	if(par[x]!=x)
	par[x]=find(parent[x]);
	return par[x];
}
void unionset(int x,int y)
{
	int x1,y1;
	x1=find(x); y1=find(y);
	if(x1!=y1)
	{
		if(rank[x1]>=rank[y1])
		{
			rank[x1]+=rank[y1];
			par[y1]=par[x1];
		}
		else 
		{
			rank[y1]+=rank[x1];
			par[x1]=par[y1];	
		}
	}
}
main()
{
	
}
