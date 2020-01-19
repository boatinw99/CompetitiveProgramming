#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
priority_queue<ll> pq;
main()
{
	ll n,i,j,max1=0,a,b,co=0 ;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a,&b);
		pq.push(b-2*a);
	} max1=n*n*-1;
	while(!pq.empty())
	{
		i=pq.top();
		pq.pop();
		co+=i;
		n--;
		max1=max(max1,co-n*n);
	}
	printf("%lld",max1);
}
