#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll n,k;
ll a[50009];
ll check(ll m)
{
	ll i=0,j=n-1;
	ll x=0;
	for(i=0;i<n;i++)
	{
		while(a[i]+a[j]>m&&j>=0)j--;
		x+=j+1;
	}
	return x;
}
main()
{
	ll i,j,x,y ;
	ll l=-1,r=80009;
	scanf("%lld %lld",&n,&k);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);	
	if(n*n==k)
	{
		printf("%lld",a[n-1]*2);
		return 0;
	}
	while(l+1<r)
	{
		ll mid=(l+r)/2 ;
		x=check(mid);
		if(x>=k)
		{
			r=mid;
			y=mid;
		}
		else if(x<k)
		{
			l=mid;
		}
	}
	printf("%lld",y);
}
