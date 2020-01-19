#include<stdio.h>
main()
{
	int a[8]={2,3,1,4,0,7,6,5},i,j,temp,b,c;
	for(i=1;i<=7;i++)
	{   j=i; b=i; c=a[i];
	   if(a[i]>a[i-1]);
	  else
	  {  
	  	for(j=i;j>0;j--)
		{
			if(a[i]<a[b-1])
			{
				b--;
			}
		}
		for(j=i;j>b;j--)
		{
			a[j]=a[j-1];
		}
		a[b]=c;
	  }
}
	for(i=0;i<=7;i++)
	{
		printf("%d ",a[i]);
	}
}
