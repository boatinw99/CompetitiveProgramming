#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<pair<ll,ll> > v[10009];
vector<pair<ll,ll> > ::iterator it;
priority_queue<pair<ll,pair<ll,ll> > > pq;
bool b[10009][10];
main()
{
	ll n,m,t,i,j,st,ed,x,y,wi,ti ;
	scanf("%lld %lld %lld",&n,&m,&t);
	scanf("%lld %lld",&st,&ed);
	while(m--)
	{
		scanf("%lld %lld %lld",&x,&y,&wi);
		v[x].push_back({y,wi});
	}
	for(it=v[st].begin();it!=v[st].end();it++)
	{
		ti=2;
		if(ti>t)ti=1;
		pq.push({it->second*-1,{it->first,ti}});
	}
	b[st][1]++;
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		y=pq.top().second.first;
		ti=pq.top().second.second;
		pq.pop();
		if(y==ed&&ti==t)
		{
			printf("%lld",x);
			return 0;
		}
		if(!b[y][ti]++)
		{
			ti++;
			if(ti>t)ti=1;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				if(!b[it->first][ti])
				{
					pq.push({-x-it->second,{it->first,ti}});
				}
			}
		}
	}
	printf("-1");
}
