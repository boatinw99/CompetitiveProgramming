#include<bits/stdc++.h>
using namespace std ;
vector<int>v[59];
int times=0;
int disc[59],low[59],parent[59];
bool pr[59];
void dfs(int i)
{
	vector<int>::iterator it;	
	times++;
	disc[i]=low[i]=times;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(disc[*it]==0)
		{
			parent[*it]=i;
			dfs(*it);
			low[i]=min(low[i],low[*it]);
			if(low[*it]>disc[i])printf("%d %d\n",i,*it);
		}
		else if(parent[i]!=*it)
		{
			low[i]=min(low[i],disc[*it]);
		}
	}
}
main()
{
	int n,m,i,j,x,y ;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
//	for(i=0;i<n;i++)disc[i]=low[i]=parent[i]=-1;
	dfs(0);
}
