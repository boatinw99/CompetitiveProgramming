#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll s[29],qs[29],*p;
main()
{
	ll i,j,n,k=1,x;
	scanf("%lld",&n);
	s[0]=1;
	for(i=1;i<=20;i++)
	{
		s[i]=s[i-1]*3;
	}
	qs[0]=1;
	for(i=1;i<=20;i++)qs[i]=s[i]+qs[i-1];
	k=0; int co=0;
	while(n!=0)
	{
		if(n>0)p=lower_bound(qs,qs+22,n);
		else p=lower_bound(qs,qs+22,-n);
		k++;
		x=p-qs;
		if(n>0)
		{
			co+=s[x];
			n-=s[x];
		}
		else 
		{
			n+=s[x];
		}
		
	}
	printf("%lld %lld",k,co);
}
