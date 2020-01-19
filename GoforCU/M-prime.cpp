#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll prime[9]={3,7,31,127,8191,131071,524287,2147483647,2305843009213693951};
ll Prime[109];
bool b[109];
main()
{
	ll i,j,p ;
	ll m,x ;
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&x);
		printf("%s \n",(binary_search(prime,prime+9,x))?("YES"):("NO"));
	}
}
