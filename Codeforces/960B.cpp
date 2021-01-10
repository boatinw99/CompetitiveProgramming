#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll> pq;
ll s[1009][2] ;
main()
{
	ll n,k1,k2,i,co=0,x ;
	scanf("%I64d %I64d %I64d",&n,&k1,&k2);
	for(i=0;i<n;i++)scanf("%I64d",&s[i][0]);
	for(i=0;i<n;i++)scanf("%I64d",&s[i][1]),pq.push(max(s[i][0]-s[i][1],s[i][1]-s[i][0]));
	k1+=k2;
	while(k1--)
	{
		x=pq.top();
		pq.pop();
		if(x>0)x--;
		else x++;
		pq.push(x);
	}
	while(!pq.empty())co+=pq.top()*pq.top(),pq.pop();
	printf("%I64d",co);
}
