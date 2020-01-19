#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> > q;
vector<pair<int,int> > v[300009];
vector<pair<int,int> >::iterator it;
set<int> t;
set<int> ::iterator it2;
bool s[300009];
bool w[300009];
main()
{
	int n,k,d,i,in,x,y;
	scanf("%d %d %d",&n,&k,&d);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&in);
		t.insert(in);
		s[in]=1;
	}
	for(it2=t.begin();it2!=t.end();it2++)
	{
		q.push({*it2,-1});
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back({y,i});
		v[y].push_back({x,i});	
	}
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for(it=v[x].begin();it!=v[x].end();it++)
		{
			if(it->first==y);
			else if(w[it->second]==1);
			else if(s[it->first]==1)
			{	
				w[it->second]=1;
			}
			else  
			{
				s[it->first]=1;
				q.push({it->first,x});
			}
		}
	}
	int count=0;
	for(i=1;i<n;i++)
	{
		if(w[i]==1)count++;
	}
	printf("%d\n",count);
	for(i=1;i<n;i++)
	{
		if(w[i]==1)printf("%d ",i);
	}
}
