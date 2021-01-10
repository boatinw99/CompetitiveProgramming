#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[1000009];
main()
{
	ll n,i,j ; 
	scanf("%I64d",&n);	
	for(i=2;i<=1000000;i++)
	{	
		if(!s[i])
		{
			for(j=2;i*j<=1000000;j++)s[j*i]=i;
		}
	}
	ll min1=INT_MAX;
	for(i=n-1;i>n-s[n];i--)
	{
		if(s[i]==0)min1=min(min1,i);
		else
		min1=min(min1,i-s[i]+1);
	}
	printf("%I64d",min1);
}
