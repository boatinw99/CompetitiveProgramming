#include<stdio.h>
int s[109];
main()
{
	int n,x,i,y;
	scanf("%d %d",&n,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&y);
		s[y]++;
	}
	int count=0;
	for(i=0;i<x;i++)
	{
		if(s[i]=
		=0)
		{
			count++;	
		}
	}
	if(s[x]==1)count++;
	printf("%d",count);
}
