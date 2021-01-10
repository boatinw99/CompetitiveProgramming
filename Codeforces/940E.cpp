#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100009];
ll dy[100009];
priority_queue<pair<int,int> > pq;
main()
{
	ll n,c,i,count=0 ;
	scanf("%I64d %I64d",&n,&c);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&s[i]);
		count+=s[i];
	}
	for(i=0;i<c&&i<n;i++)
	{
		pq.push({-s[i],i});
	}
	if(c>n)return 0*printf("%I64d",count);
	dy[c-1]=pq.top().first*-1;
	for(i=c;i<n;i++)
	{
		pq.push({-s[i],i});
		while(pq.top().second<=i-c)pq.pop();
		dy[i]=max(dy[i-1],pq.top().first*-1+dy[i-c]);
	}
	ll max1=0;
	for(i=1;i<=c;i++)
	{
		max1=max(max1,dy[n-i]);
	}
	printf("%I64d",count-max1);
}
