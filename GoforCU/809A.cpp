#include<bits/stdc++.h>
typedef long long ll ;
using namespace std;
const ll e=1e9+7;
ll a,s[300009];
main()
{
	ll i,count1=0,count2=0,x,y,c=2 ;
	scanf("%I64d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%I64d",&s[i]);
	}
	sort(s+1,s+a+1);
	for(i=2;i<=a;i++)
	{
		count1=(count1+(s[i]-s[1])*(c-1))%e;
		count2=(count2+(s[a-i+1]-s[1])*(c-1))%e;
		c=(c*2)%e;
	}
	if(count1>=count2)
	{
		printf("%I64d",(count1-count2)%e);
	}
	else 
	{
		printf("%I64d",(e+((count1-count2)%e))%e);
	}
}
