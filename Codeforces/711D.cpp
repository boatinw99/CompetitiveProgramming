#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9+7;
ll s[200009],n,pr=1,co=1 ;
ll b[200009];
ll dfs(ll i)
{
	ll k ;
	b[i]=2;
	if(b[s[i]]==2)
	{
		b[i]=1;
		co*=2;
		return s[i];	
	}
	else if(b[s[i]]==0)
		k=dfs(s[i]);
	co*=2;	
	if(k==i)co-=2;
	co=co%N;
	b[i]=1;
	return k;
}
main()
{
	ll i;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)scanf("%I64d",&s[i]);
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			co=1;
			dfs(i);
			pr=(pr*co)%N;
		}
	}
	printf("%I64d",pr);
}
