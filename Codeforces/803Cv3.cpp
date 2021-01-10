#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
	ll n,k,pr=0,i;
	scanf("%I64d %I64d",&n,&k);
	ll ch=k*(k+1)/2;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i>=ch)pr=max(pr,n/i);
			if(n/i>=ch)pr=max(pr,i);	
		}
	}
	if(pr==0||k>150000)return 0 *printf("-1");
	for(i=1;i<k;i++)printf("%I64d ",pr*i);
	printf("%I64d",n-((k-1)*k/2)*pr);
}
