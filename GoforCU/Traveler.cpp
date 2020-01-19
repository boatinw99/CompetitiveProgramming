#include<bits/stdc++.h>
using namespace std;
int n,m,st,ed,d ;
vector<pair<int,int> >v[10009];
vector<pair<int,int> >::iterator it;
priority_queue<pair<int,int> > pq;
int s[10009];
bool b[10009];
main()
{
	int i,j,k,x,y,val ;
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&st,&ed,&d);
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&val);
		v[x].push_back({y,val});
		v[y].push_back({x,val});
	}
	pq.push({0,ed});
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		y=pq.top().second;
		pq.pop();
		if(!b[y]++)
		{
			s[y]=x;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(!b[it->first])
				pq.push({-x-it->second,it->first});
			}
		}
	}
	for(i=0;i<=n;i++)b[i]=0;
	pq.push({0,st});
	int pr,max1,max2=INT_MAX;
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		y=pq.top().second;
		pq.pop();
		if(!b[y]++&&x<=d)
		{
			if(s[y]<max2)
			{
				max2=s[y];
				max1=x;
				pr=y;
			}	
			if(s[y]==max2&&y<pr)
			{
				max1=x;
				pr=y;
			}
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(!b[it->first])
					pq.push({-x-it->second,it->first});
			}
		}
	}
	printf("%d %d %d",pr,max1,max2);
}
