#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[50009];
vector<pair<int,int> >::iterator it;
priority_queue<pair<int,int> >pq;
bool b[50009];
main()
{
	int n,m,c=0,x,y,i,j,val,co=0 ;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&x);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&val);
		c+=val;
		v[x].push_back({y,val});
		v[y].push_back({x,val});
	}
	for(it=v[x].begin();it!=v[x].end();it++)
	{
		pq.push({it->second,it->first});
	}
	b[x]++;
	while(!pq.empty())
	{
		x=pq.top().first;
		y=pq.top().second;
		pq.pop();
		if(!b[y]++)
		{
			co+=x;	
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				pq.push({it->second,it->first});
			}
		}
	}
	printf("%d",c-co);
}
