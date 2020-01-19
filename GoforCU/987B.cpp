#include<stdio.h>
main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==1&&b==1)printf("=");
	else if(a==1)printf("<");
	else if(b==1)printf(">");
	else if(a==2&&b==3)printf("<");
	else if(a==3&&b==2)printf(">");
	else if(a==2&b==4)printf("=");
	else if(a==4&&b==2)printf("=");
	else if(a<b)
	{
		printf(">");
	}
	else if(a>b)printf("<");
	else printf("=");
}
