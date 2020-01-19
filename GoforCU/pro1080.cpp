#include<bits/stdc++.h>
using namespace std ;
int s[30009],*p;
int max1=0;
main()
{
	int i,n,j,co=0 ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	} sort(s+1,s+n+1);
	co=s[1];
	for(i=2;i<=n;i++)
	{
		co+=s[i]; co-=s[i-2];
		p=upper_bound(s+1,s+n+1,co);
		j=p-s;
		max1=max(max1,j-i+1);
	}
	if(max1<=2)printf("0");
	else printf("%d",max1);
}
