#include<bits/stdc++.h>
using namespace std ;
int s[1009];
main()
{
	int n,i,co=0,x,y ;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		s[x]++; s[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]==1)co++;
	}
	printf("%d",co);
}
