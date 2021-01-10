#include<stdio.h>
main()
{
	int a,i,a1,a2,k=0,max=0;
	scanf("%d",&a);
	int s[(a*2)+1];
	for(i=0;i<=a*2;i++)s[i]=0;
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&a1,&a2);
		s[a1]++;
		s[a2]--;
	}
	for(i=1;i<=a*2;i++)
	{
		if(s[i]==1)
		{
			k++;
			s[i]=k;
		}
		else if(s[i]==-1)
		{
			s[i]=k;
			k--;
		}
		else 
		{
			s[i]=k;
		}
	}
	for(i=1;i<=a*2;i++)
	{
		if(s[i]>max)max=s[i];
	}
	printf("%d",max);
}
