#include<bits/stdc++.h>
using namespace std;
int s[109];
main()
{
	int n,d,i,j;
	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	int max=1000;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(s[j]-s[i]>d)break;
		}
		max=min(n-(j-i),max);
		
	}
	printf("%d",max);
}
