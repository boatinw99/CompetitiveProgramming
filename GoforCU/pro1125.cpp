#include<bits/stdc++.h>
using namespace std ;
long long a[500009],b[500009];
main()
{
	long long i,j,n;
	long long co=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a[i],&b[i]);
	}
	sort(a+1,a+n+1); 
	sort(b+1,b+n+1);
	for(i=2;i<=n;i++)
	{
		co+=(a[i]-a[i-1])*(i-1)*(n-i+1);
		co+=(b[i]-b[i-1])*(i-1)*(n-i+1);
	}
	printf("%lld",co);
}
