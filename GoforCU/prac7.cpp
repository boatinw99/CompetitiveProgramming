#include<bits/stdc++.h>
using namespace std ;
const int N=509;
int disc[N],low[N],times=1,parent[N];
bool pr[N];
vector<int>v[N];
void dfs(int i)
{
	vector<int>::iterator it;
	disc[i]=low[i]=times++;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(disc[*it]==0)
		{
			parent[*it]=i;
			dfs(*it);
			low[i]=min(low[i],low[*it]);
			if(disc[i]<low[*it])printf("%d %d\n",i,*it);
		}
		else if(parent[i]!=*it)
		{
			low[i]=min(low[i],disc[*it]);
		}
	}
}
main()
{
	int n,m,x,y,i ;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(disc[i]==0)
		dfs(i);
	}
}
