#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<pair<int,int> > v[300009];
vector<pair<int,int> >::iterator it;
bool s[300009];
set<int> e;
set<int>::iterator it2;
main()
{
	int n,k,d,i,in,x,y;
	scanf("%d %d %d",&n,&k,&d);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&in);
		q.push(in);
		s[in]=1;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back({y,i});
		v[y].push_back({x,i});	
		e.insert(i);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(it=v[x].begin();it!=v[x].end();it++)
		{
			if(s[it->first]==0)
			{
				e.erase(it->second);
				s[it->first]=1;
				q.push(it->first);
			}
		}
	}
	printf("%d\n",e.size());
	for(it2=e.begin();it2!=e.end();it2++)
	printf("%d ",*it2);
}
