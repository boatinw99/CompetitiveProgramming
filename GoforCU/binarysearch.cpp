#include<bits/stdc++.h>
using namespace std;
main()
{
	int l=1,r=1e9,n,m;
	scanf("%d",&n);
	while(l+1<r)
	{
		m=(l+r)/2;
		if(m>=n)r=m;
		else l=m;
	}
	printf("%d",r);
}
