#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
	ll n,k,i,pr=1;
	scanf("%I64d %I64d",&n,&k);
	if(k>1)pr+=n*(n-1)/2;
	if(k>2)pr+=n*(n-1)*(n-2)/3;
	if(k>3)pr+=n*(n-1)*(n-2)*(n-3)/24*9;
	printf("%I64d",pr);
}
