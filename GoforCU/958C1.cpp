#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll s[100009];
main()
{
	ll n,k,i,j,co=0,pre=0,p,max1=0 ;
	scanf("%I64d %I64d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&s[i]);
		co+=s[i];
	}
	for(i=0;i<n-1;i++)
	{
		pre+=s[i]; co-=s[i];
		max1=max(max1,(pre%p)+(co%p));
	}
	printf("%I64d",max1);
}
