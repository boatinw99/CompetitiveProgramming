#include<bits/stdc++.h>
using namespace std ;
vector<int>v[100009];
int a[100009];
void dfs(int in,int parent)
{
	vector<int>::iterator it;
	a[in]=parent;
	for(it=v[in].begin();it!=v[in].end();it++)
	{
		if(a[*it]==0)
		{
			dfs(*it,parent);
		}
	}
}
main()
{
	int n,m,t,x,y;
	scanf("%d %d %d",&n,&m,&t);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			dfs(i,i);
		}
	}
	while(t--)
	{
		scanf("%d %d",&x,&y);
		if(a[x]==a[y])printf("yes");
		else printf("no");
		printf("\n");
	}
}
