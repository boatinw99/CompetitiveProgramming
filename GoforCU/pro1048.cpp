#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll s[39],co=0;
ll find(ll n)
{
	ll i;
	for(i=0;1<<i<=n;i++)
	{
		co+=s[i];
	} i--;
	n-=1<<i;
	return n;
}
main()
{
	ll k,n,i ;
	scanf("%lld %lld",&k,&n);
	s[0]=1;
	for(i=1;i<=k;i++)s[i]=s[i-1]*2;
	while(n>0)
	{
		n=find(n);
	}
	printf("%lld",co);
}
