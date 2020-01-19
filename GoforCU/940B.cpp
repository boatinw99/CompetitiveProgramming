#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
	ll n,k,a,b,count=0;
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
	while(n!=1)
	{
		if(n%k!=0)
		{
			count+=(n%k)*a;
			n-=(n%k);
			if(n==0)count-=a,n++;
		}
		else
		{
			if((n-n/k)*a<b)
			{
				count+=(n-1)*a;
				n=1;
			}
			else 
			{
				count+=b;
				n=n/k;
			}
		}
	}
	printf("%I64d",count);
}
