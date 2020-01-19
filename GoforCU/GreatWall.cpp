#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll l=0,r=1e9+7;
ll a[1000009];
ll dp[1000009];
main()
{
	ll n,w,k,i,j ;
	scanf("%lld %lld %lld",&n,&w,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	while(l+1<r)
	{
		ll mid=(l+r)/2 ;
		ll co=0;
		for(i=1;i<=n;i++)
		{
			mid+=dp[i]; dp[i]=0;
			if(a[i]>mid)
			{
				co+=a[i]-mid;
				dp[i+w]+=-(a[i]-mid);
				mid=a[i];
			}
		}
		if(co<=k)
		{
			r=(l+r)/2;
		}
		else 
		{
			l=(l+r)/2;
		}
	}
	printf("%lld",r);
}
