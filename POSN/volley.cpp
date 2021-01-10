#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,i,count=0;
	scanf("%d",&a);
	int m[a],n[a];
	for(i=0;i<a;i++)
	{
		scanf("%d",&m[i]);
	}
	for(i=0;i<a;i++)
	{
		scanf("%d",&n[i]);
	}
	sort(m,m+a);
	sort(n,n+a);
	for(i=0;i<a;i++)
	{
		if(m[i]<n[i])count+=n[i]-m[i];
		else count+=(m[i]-n[i]);
	}
	printf("%d",count);
}
