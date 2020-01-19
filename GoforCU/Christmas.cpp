#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll bit[40],pr=0,n;
void update(ll x)
{
	int i;
	for(i=0;i<=30;i++)
	{
		if((x&(1<<i))!=0)
		{
			bit[i]++;
		}
	}
}
void sum(ll x)
{
	ll i;
	for(i=0;i<=30;i++)
	{
		if((x&(1<<i))!=0)
		{
			pr+=(1<<i)*(n-bit[i]);
		}
		else
		{
			pr+=(1<<i)*bit[i];
		}
	}
}
main()
{
	ll x,i,m ;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		update(x);
	}
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&x);
		sum(x);
	}
	printf("%lld",pr);
}
