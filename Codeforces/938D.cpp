#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll n,m ;
vector<pair<ll,ll> >v[200009];
vector<pair<ll,ll> >::iterator it;
priority_queue<pair<ll,ll> >pq;
ll a[200009];
main()
{
	ll i,j,x,y,val;
	scanf("%I64d %I64d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%I64d %I64d %I64d",&x,&y,&val);
		v[x].push_back({y,val});
		v[y].push_back({x,val});
	}
	for(i=1;i<=n;i++)scanf("%I64d",&x),pq.push({-x,i});
	while(!pq.empty())
	{
		val=pq.top().first*-1;
		y=pq.top().second;
		pq.pop();
		if(!a[y])
		{
			a[y]=val;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				pq.push({(it->second*2+val)*-1,it->first});
			}
			
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%I64d ",a[i]);
	}
}
