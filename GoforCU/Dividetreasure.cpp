#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll qs[200009],*p;
main()
{
	ll n,i,j,x,y ;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&qs[i]);
		qs[i]+=qs[i-1];
	}
	ll min1=1e16,z,a1,a2,temp1,temp2;
	for(i=2;i<n;i++)
	{
		x=qs[n]-qs[i];
		y=qs[i];
		p=lower_bound(qs+1,qs+i,y/2);
		if(*p==y)p--;
		for(j=1;j<=2&&p>qs+1;j++,p--)
		{
			a1=*p; a2=y-*p;
			temp1=min(a1,a2);
			temp1=min(temp1,x);
			temp2=max(a1,a2);
			temp2=max(temp2,x);
			min1=min(min1,temp2-temp1);	
		}
		
	}
	printf("%lld",min1);
}
