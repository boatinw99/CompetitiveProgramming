#include<stdio.h>
main()
{
	int a[8]={2,3,1,4,0,7,6,5},i,j,temp;
	for(i=7;i>=1;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<=7;i++)
	{
		printf("%d ",a[i]);
	}
	
}
