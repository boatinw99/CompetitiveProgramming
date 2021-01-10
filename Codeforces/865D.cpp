#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<pair<ll,bool> > pq;
ll s[300009];
main()
{
	ll n,i,count=0,x;
	bool b;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&s[i]);
	}
	pq.push({s[n-1],0});
	for(i=n-2;i>=0;i--)
	{
		if(s[i]>=pq.top().first)
		{
			pq.push({s[i],0});
		}
		else
		{
			count+=pq.top().first-s[i];
			x=pq.top().first;
			b=pq.top().second;
			pq.pop();
			pq.push({s[i],1});
			if(b==1)
			{
				pq.push({x,0});
			}
		}
	}
	printf("%I64d",count);
}
