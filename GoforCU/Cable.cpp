#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >pq;
vector<pair<int,int> >v[2509];
vector<pair<int,int> >::iterator it;
int st,ed,P;
bool b[2509];
main()
{
	int n,m,x,y,wi ;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&wi);
		v[x].push_back({y,wi});
		v[y].push_back({x,wi});
	}
	scanf("%d %d %d",&st,&ed,&P);
	pq.push({INT_MAX,st});
	while(!pq.empty())
	{
		x=pq.top().first;
		y=pq.top().second; pq.pop();
		if(!b[y]++)
		{
			if(y==ed)break;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(!b[it->first])
				{
					if(it->second<x)pq.push({it->second,it->first});
					else pq.push({x,it->first});
				}
			}
		}
	}
	printf("%d",((P-1)/(x-1))+1);
}
