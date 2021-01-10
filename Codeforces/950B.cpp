#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll a[100009],b[100009];
main()
{
	ll n,m,i,j,co1=0,co2=0,pr=0 ;
	scanf("%I64d %I64d",&n,&m);
	for(i=0;i<n;i++)scanf("%I64d",&a[i]);
	for(i=0;i<m;i++)scanf("%I64d",&b[i]);
	j=0;
	co2=b[0];
	for(i=0;i<=n;)
	{
		if(co1==co2)
		{
			pr++;j++;
			co1=0;co2=b[j];
		}
		else if(co1<co2)
		{
			co1+=a[i];	
			i++;
		}
		else if(co1>co2)
		{
			j++;
			co2+=b[j];
		}
		if(j>=m)break;
	}
	printf("%I64d",pr);
}
