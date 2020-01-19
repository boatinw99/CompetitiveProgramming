#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int> > v[100009];
vector<pair<int,int> > ::iterator it;
priority_queue<pair<int,pair<int,int> > > pq;
int b[100009];
main()
{
	int i,n,m,x,y,wi,co=0 ;
	scanf("%d %d",&n,&m); 
	for(i=1;i<=n;i++)b[i]=100599;
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&wi);
		v[x].push_back({y,wi});
		v[y].push_back({x,wi});
	}
	b[1]=0;
	for(it=v[1].begin();it!=v[1].end();it++)
	{
		b[it->first]=it->second;
		pq.push({it->second*-1,{it->first,1}});
	}
	while(!pq.empty())
	{
		wi=pq.top().first*-1;
		y=pq.top().second.first;
		x=pq.top().second.second;
		pq.pop();  	
		if(b[y]==wi)
		{	
			b[y]=0;
			printf("%d %d\n",x,y);
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(it->second<b[it->first])
				{
					b[it->first]=it->second;
					pq.push({it->second*-1,{it->first,y}});
				}
			}
		}
	}
}
