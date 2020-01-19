#include<bits/stdc++.h>
using namespace std ;
vector<int>v[50009];
vector<int> q;
bool b[50009];
void dfs(int i)
{
	vector<int>::iterator it;
	b[i]++;
	if(v[i].size()==1)
	{
		q.push_back(i);
		return ;
	}
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(b[*it]==0)
		{
			dfs(*it);
		}
	}
}
main()
{
	int n,m,x,y ;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int>::iterator it,it1;
	int root=1;
	if(n==2)
	{
		printf("1\n");
		if(m==2)printf("1 2");
		return 0;
	}	
	while(v[root].size()==1)root++;	
	dfs(root);
	int co=q.size()+1;
	co/=2;
	printf("%d\n",co);
	if(m==2)
	{
		for(int i=0;i<co;i++)
		{
			printf("%d %d\n",q[i],q[i+q.size()/2]);
		}
	}
}
