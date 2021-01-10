#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100009],n,x,k,*p1,*p2 ;
main()
{
	ll i,count=0;
	scanf("%I64d %I64d %I64d",&n,&x,&k);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&s[i]);
	}
	sort(s,s+n);
	for(i=0;i<n;i++)
	{
		p1=lower_bound(s,s+n,max(s[i],s[i]/x*x+x*(k-(!(s[i]%x)))));
		p2=lower_bound(s,s+n,s[i]/x*x+x*(k+1-(!(s[i]%x))));
		count+=p2-p1;
	}
	printf("%I64d",count);
}
