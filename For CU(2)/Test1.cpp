#include<bits/stdc++.h>
using namespace std ;
vector<vector<pair<long long,long long> > > v(1000001);
vector<pair<long long,long long> >::iterator it ;
priority_queue<pair<long long,long long> > pq;
main()
{
	long long a,max,i,k=0;
	long long x,y,q;
	scanf("%lld %lld",&max,&a);
	for(i=0;i<a;i++)
	{
		scanf(" %lld %lld",&x,&y);
		v[y].push_back({0,x});
	}
	v[max].push_back({max-1,max-1});
	for(it=v[max].begin();it!=v[max].end();it++)
	{
		pq.push({it->first*-1,it->second});
	}
	while(!pq.empty()&&k==0)
	{
		x=pq.top().first;
		q=pq.top().second;
		pq.pop();
		if(q==1){printf("%lld",-x);k=99;break;}
		for(it=v[q].begin();it!=v[q].end();it++)
		{
			pq.push({it->first*-1+x,it->second});
		}
		pq.push({1-q+x,q-1});
	}
}
