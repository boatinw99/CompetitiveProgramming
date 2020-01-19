#include<bits/stdc++.h>
using namespace std ;
int a[100009];
int gr[100009][109];
bool b[100009][109];
vector<int>path[100009];
vector<int>goods[109];
queue<pair<int,int> >q;
void bfs(int x)
{
	int l,r;
	vector<int>::iterator it,it1;
	for(it=goods[x].begin();it!=goods[x].end();it++)q.push({0,*it}),b[*it][x]++;
	while(!q.empty())
	{
		l=q.front().first;
		r=q.front().second;
		q.pop();
		gr[r][x]=l;
		for(it=path[r].begin();it!=path[r].end();it++)
		{
			if(!b[*it][x]++)
			{
				q.push({l+1,*it});
			}
		}
	}
}
main()
{
	int n,m,s,k,i,j,x,y ;
	scanf("%d %d %d %d",&n,&m,&s,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		goods[a[i]].push_back(i);
	}
	while(m--)
	{
		scanf("%d %d",&x,&y);
		path[x].push_back(y);
		path[y].push_back(x);
	}
	priority_queue<int> pq;
	for(i=1;i<=s;i++)
	{
		bfs(i);
	}
	int co ;
	for(i=1;i<=n;i++)
	{
		co=0;
		for(j=1;j<=s;j++)
		{
			pq.push(-gr[i][j]);
		}
		for(j=1;j<=k;j++)
		{
			co+=pq.top()*-1;
			pq.pop();
		}
		while(!pq.empty())pq.pop();
		printf("%d ",co);
	}
	
}
