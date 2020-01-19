#include<stdio.h>
main()
{
	int n,k,i,j,l,r,len ;
	scanf("%d %d",&n,&k);
	for(i=3;i<=n;i++)
	{
		 len=i-(i-1)/2-1;
		 len=(i-1)-len;
		 if((k-2)*len+i>=n)
		 break;
	}
	printf("%d",i-1);
	for(j=1;j<=i-1;j++)
	{
		printf("\n%d %d",j,j+1);
	}
	int d=1,co=2;
	for(j=i+1;j<=n;j++)
	{
		printf("\n%d %d",(i+1)/2,j);
		co++;
		for(d=1;d<len&&j+1<=n&&n-j>k-co;d++,j++)
		{		
			printf("\n%d %d",j,j+1);
		}
	}
}
