#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[10009];
ll qs[10009];
main()
{
	ll i,n,j,k,p=1;
	ll co=0 ;
	const ll mod=49999;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
	}
	for(k=1;k<=n-2;k++)p=(p*k)%mod;
	for(i=1;i<n;i++)
	{
		qs[i]=(qs[i-1]+(s[i]-s[i-1])*i)%mod;
		co=(co+(qs[i]*p))%mod;
	}
	printf("%lld",co);
	
}
