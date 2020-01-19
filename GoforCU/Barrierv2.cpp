#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll max1=0,range=0;
ll s[6000009] ;
main()
{
	ll n,k,i,j=0,co=0 ; 
	scanf("%lld %lld",&n,&k);
	for(i=0;i<n;i++)scanf("%lld",&s[i]);
	for(i=0;i<n;i++)
	{
		co+=s[i];
		if(i-j==k)co-=s[j],j++;
		while(s[j]<=0&&j<=i)co-=s[j],j++;
		if(co<=0)j=i+1,co=0;
		printf("%d %d %d\n",j,i,co);
		if(co>max1)max1=co,range=i-j+1;
		else if(co==max1)range=min(range,i-j+1);
	}
	printf("%lld\n%lld",max1,range);
}
