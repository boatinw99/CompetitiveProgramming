#include<stdio.h>
main()
{
	int a[8]={2,3,1,4,0,7,6,5},i,j,temp,b;
	for(i=1;i<=7;i++)
	{   b=7;
		for(j=7;j>=i;j--)
		{
			if(a[b]>a[j-1])
			{
				b=j-1;
			}
		}
		temp=a[i-1];
		a[i-1]=a[b];
		a[b]=temp;
	}
	for(i=0;i<=7;i++)
	{
		printf("%d ",a[i]);
	}
}
