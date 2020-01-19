#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
pair<ll,ll>s[500009],q[500009];
main()
{
	ll i,n,j,a=0,b=0,x,y,wi,pe=0,pr=0,min1,l,r ;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&wi);
		s[i]={x,wi};
		q[i]={y,wi};
		a+=x*wi;
		b+=y*wi;
		pe+=wi;
	}
	sort(s+1,s+n+1); sort(q+1,q+n+1);
	min1=b; l=0,r=pe;
	ll co=b;
	for(i=1;i<=n;i++)
	{
		x=q[i].first-q[i-1].first;
		co+=l*x ; co-=r*x;
		l+=q[i].second; r-=q[i].second;
		min1=min(min1,co);
	}
	pr+=min1;
	min1=a; l=0,r=pe; co=a;
	for(i=1;i<=n;i++)
	{
		x=s[i].first-s[i-1].first;
		co+=l*x ; co-=r*x;
		l+=s[i].second ; r-=s[i].second;
		min1=min(min1,co);
	}
	pr+=min1;
	printf("%lld",pr);
}
