#include<stdio.h>
main()
{
	int a,i ;
	scanf("%d",&a);
	for(i=1;;i++)
	{
		if(i*i>=a)break;
	}
	if(i*i==a)
	{
		printf("%d",4*i);
	}
	else 
	{
		if(i*i-a>=i)
		{
			printf("%d",4*i-2);
		}
		else 
		printf("%d",4*i);
	}
}
