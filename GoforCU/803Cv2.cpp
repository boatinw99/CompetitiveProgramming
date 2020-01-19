#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
	ll n,k ;
	scanf("%I64d %I64d",&n,&k);
	if(k>150000||k*(k+1)/2>n)return 0*printf("-1");
	ll ch=k*(k+1)/2;
	ll pr=0,i;	
	ll d=100000;
	i=min(d,ch);
	for(i;i>=1;i--)
		if(n%i==0)
		{
			if((n/i)>=ch)
			{
				pr=n/(n/i);
				break;	
			}
		}
	for(i=ch;i<=100000&&i*i<=n;i++)
		if(n%i==0)
		{
			pr=n/i;
			break;
		}
	if(pr==0)return 0*printf("-1");
	for(i=1;i<k;i++)
	{
		printf("%I64d ",pr*i);
	}
	printf("%I64d",n-((k-1)*k)/2*pr);
}
