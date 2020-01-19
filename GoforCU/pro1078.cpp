#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[1000009];
main()
{
	ll i,n,j,co=0 ;
	scanf("%lld",&n);
	for(i=0;i<n;i++)scanf("%lld",&s[i]);
	sort(s,s+n);
	for(i=0;i<n/2;i++)
	{
		co+=s[n-i-1]-s[i];
	}
	printf("%lld",co);
}
