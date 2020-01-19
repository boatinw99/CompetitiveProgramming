#include<bits/stdc++.h>
using namespace std ;
vector<int>v[59];
int disc[59],low[59],parent[59],pr[59];
int times=0;
void dfs(int i)
{
	disc[i]=low[i]=times;
	times++;
	vector<int>::iterator it;
	int child=0;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(disc[*it]==-1)
		{
			child++;
			parent[*it]=i;
			dfs(*it);
			low[i]=min(low[i],low[*it]);
			if(parent[i]==-1&&child>1)pr[i]++;
			if(parent[i]!=-1&&disc[i]<=low[*it])pr[i]++;
		}
		else if(parent[i]!=*it)
		{
			low[i]=min(low[i],disc[*it]);
		}
	}
}
main()
{
	int n,m,x,y ;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=0;i<=n;i++)disc[i]=low[i]=parent[i]=-1;
	dfs(1);
	for(int i=1;i<=n;i++)if(pr[i])printf("%d ",i);
}
