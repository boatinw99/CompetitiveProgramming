#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
priority_queue<ll> pq1,pq2;
main()
{
	ll pr=0,n,k,i,x,y ;
	scanf("%lld %lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		pq1.push(x);
		pq2.push(-x);
	}
	ll z;
	while(pq1.top()+pq2.top()>k)
	{
		x=pq1.top();
		y=pq2.top()*-1;
		pq1.pop(); pq2.pop();
		//z=(x-y-k-1)/2+1;
		pr++;
		x--;
		y++;
		pq1.push(x);
	    pq2.push(-y);
	}
	printf("%lld",pr);
}
