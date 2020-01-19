#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
main()
{
	ll gc=0,m,x,co=0,i ;
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&x);
		gc=__gcd(gc,x);
	}
	for(i=1;i*i<gc;i++)
	{
		if(gc%i==0)co+=2;
	}
	if(i*i==gc)co++;
	printf("%d",co);
}
