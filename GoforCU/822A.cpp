#include<stdio.h>
main()
{
	int a,b,c=1 ;
	scanf("%d %d",&a,&b);
	if(a>b)a=b;
	while(a>0)
	{
		c*=a;
		a--;
	}
	printf("%d",c);
}
