#include<stdio.h>
main()
{
	int a[10]={0},b,c,i;
	scanf("%d",&b);
	scanf("%d",&c);
	for(b;b<=c;b++)
	{   i=b;
		a[i%10]++;
		if(i>=10)
		{
			i=i/10;
			a[i]++;
		}
	}
	for(i=0;i<=9;i++)
	{
		printf("%d %d\n",i,a[i]);
	}
}
