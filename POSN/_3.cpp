#include<stdio.h>
main()
{
	int a[5]={0},b,c,i,j;
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{
		for(j=0;j<=4;j++)
		{
			scanf(" %d",&c);
			a[j]=a[j]+c;
		}
	}
	b=a[0]*8+a[1]*3*2+a[2]*4+a[3]*2+a[4];
	c=b/8;
	if(b%8!=0)
	{
		c++;	
	}	
	printf("%d",c);
}
