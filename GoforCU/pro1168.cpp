#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
vector<ll> v;
ll Call(ll s)
{
	ll c=s%10,i;
	v.push_back(s);
	for(i=c+1;i<=9;i++)
	{
		Call(s*10+i);
	}
}
main()
{
	ll m,i,x;
	for(i=1;i<=9;i++)
	{
		Call(i);
	}
	sort(v.begin(),v.end());
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&x);
		if(x>v.size())printf("-1");
		else printf("%lld",v[x-1]);
		printf("\n");
	}
	printf("%d",v.size());
}
