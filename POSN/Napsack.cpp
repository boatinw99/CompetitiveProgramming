#include<stdio.h>
int a[20]={0},kg,p=0;
Weight(int i,int value,int kg1)
{   
	if(kg1<=kg)
	{	
		if(value>p)
			{
				p=value;
			}
		for(i=0;i<20;i++)
		{
			if(a[i]!=0)
			{
			//	printf("%d %d\n",kg1,value);
				Weight(i,value+a[i],kg1+i);
			}
		}
		
	}
	
}
main()
{  int n,i,temp,temp1;
	scanf("%d",&kg);
	scanf(" %d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d",&temp,&temp1);
		a[temp]=temp1;
	}
	for(i=0;i<20;i++)
	{
		if(a[i]!=0)
		{
			Weight(i,a[i],i);
		}
	}
	printf("%d",p);
}
