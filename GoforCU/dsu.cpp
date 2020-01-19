#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int rank[1000];
int findset(int in)
{
	if(parent[in]!=parent[parent[in]])
	parent[in]=findset(parent[in]);
	return parent[in];
}
void unionset(int a,int b)
{
	int l,r;
	l=findset(a); r=findset(b);
	if(l!=r)
	{
		if(rank[l]>=rank[r])
		{
			rank[l]+=rank[r];
			parent[r]=l;
		}
		else
		{
			rank[r]+=rank[l];
			parent[l]=r;
		}
	}
}
main()
{
	int i;
	for(i=0;i<1000;i++)parent[i]=i,rank[i]=1;
	printf("%d\n",findset(2));
	unionset(2,3);
	unionset(2,1);
	printf("%d\n",findset(2));
}
