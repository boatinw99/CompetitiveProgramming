#include<bits/stdc++.h>
using namespace std ;
int a[2009];
int l=-1,r=1e6+9;
main()
{
	int n,m,k,i,j ;
	scanf("%d %d %d",&n,&k,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(l+1<r)
	{
		int mid=(l+r)/2 ;
		int co=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>mid)
			{
				i+=k-1;
				co++;
			}
		}
		if(co<=m)r=mid;
		else l=mid;
	}
	printf("%d\n",r);
}
