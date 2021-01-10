#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
main()
{
	ll n,k,i;
	scanf("%I64d %I64d",&n,&k);
	ll pr=n;
	for(i=0;i<k;i++)
	{
		ll cr=n%10;
		if(cr%5==0&&cr%2==0)
		{
			n/=10;
		}
		else if(cr%5==0)
		{
			pr*=2;
			n*=2;
			n/=10;
		}
		else if(cr%2==0)
		{
			pr*=5;
			n*=5;
			n/=10;
		}
		else 
		{
			pr*=10;
			n*=10;
			n/=10;
		}
	}
	printf("%I64d",pr);
}
