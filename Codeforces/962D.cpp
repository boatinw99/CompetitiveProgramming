#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
priority_queue<pair<ll,ll> > pq;
vector<pair<ll,ll> > v;
vector<pair<ll,ll> >::iterator it;
main()
{
	ll n,i,j,k,x,y;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		pq.push({-x,-i});
	}
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		y=pq.top().second*-1;
		pq.pop();
		if(pq.empty()||x!=pq.top().first*-1)
		{
			v.push_back({y,x});
		}
		else
		{
			y=pq.top().second*-1;
			pq.pop();
			pq.push({-2*x,-y});
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for(it=v.begin();it!=v.end();it++)printf("%I64d ",it->second);
}
