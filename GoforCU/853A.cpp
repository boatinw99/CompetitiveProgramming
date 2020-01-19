#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<pair<ll,ll> > p;
priority_queue<ll> q;
ll s[300009];
main()
{
	ll n,k,i,x,y,count=0;
	scanf("%I64d %I64d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&s[i]);
		p.push({s[i],i});
	}
	k++;
	while(!p.empty())
	{
		x=p.top().first;
		y=p.top().second;
		p.pop();
		while(!q.empty()&&q.top()==-k)
		{
			k++;
			q.pop();
		}
		if(y>k)
		{
			q.push(-y);
			s[y]=y;
		}
		else 
		{
			count+=(k-y)*x;
			s[y]=k;
			k++;
		}
	}
	printf("%I64d\n",count);
	for(i=1;i<=n;i++)
	{
		printf("%I64d ",s[i]);
	}
}
