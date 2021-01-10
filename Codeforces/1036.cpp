#include<bits/stdc++.h>
using namespace std;
int s[257];
main()
{
	int n,k,i,j,x,co,d=0,p ;
	scanf("%d %d",&n,&k);
	for(i=0;i<256;i++)s[i]=1e6;
	int b=1 ; for(i=0;i<k-1;i++)b*=2;
	while(n--)
	{
		co=b; d=0;
		scanf("%d",&x);
		for(j=0;j<k;j++)
		{
			scanf("%d",&p);
			d+=co*p;
			co/=2;
		}
		s[d]=min(s[d],x);
		for(j=1;j<=b*2-1;j++)
		{
			s[j|d]=min(s[j]+s[d],s[j|d]);
		}
	} 
	printf("%d",s[b*2-1]);
}
