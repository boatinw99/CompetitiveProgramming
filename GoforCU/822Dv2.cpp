#include<bits/stdc++.h>
using namespace std;
const int N=5e6+9;
typedef long long ll ;
ll m=1e9+7;
ll prime[N],s[N];
main()
{
	ll t,l,r,i,n=1,j ;
	scanf("%I64d %I64d %I64d",&t,&l,&r);
	for(i=2;i<=r;i++)
	{
		if(!s[i])
		{
			s[i]=i;
			prime[n++]=i;
		}
		for(j=1;j<n&&i*prime[j]<=r;j++)
			s[prime[j]*i]=min(prime[j],s[i]);
		
	}
	ll count=0 ;
	for(i=2;i<=r;i++)
	{
	
		if(s[i]==i)s[i]=i*(i-1)/2;
		else
		{
			s[i]=(i/s[i])*s[s[i]]+s[i/s[i]];	
		}
		s[i]%=m;	
	}
	for(i=r;i>l;i--)
		count=((count+s[i])*t)%m;
	count=(count+s[l])%m;	
		//count=(t*count+s[i])%m;
	printf("%I64d",count);
}
