#include<bits/stdc++.h>
using namespace std ;
main()
{
	long long a,b,g,count,count1=INT_MAX*-1,k=0;
	scanf("%I64d %I64d",&b,&a);
	long long c=a,d,f=b;
	while(1)
	{
		count =0;
		d=(a+b)/2;
		g=d;
		while(g>0)
		{
			count+=g%10;
			g=g/10;
		}
		if(b-d<=10&&d-count>=c)
		{	
			break;
		}
	//	printf("%I64d %I64d %I64d\n",a,b,d);
		if(count1==d&&a!=b)
		{
			a=b;
		}
		else if(count1==d)
		{
			k=1;
			printf("0");
			break;	
		}
		else 
		{
		if(d-count>=c)
		b=d;
		else if(d-count<c)
		a=d;
		count1=d;
		}
	}
	if(k==0)
	{
		d=d-(d%10);
	d=f-d+1;
	printf("%I64d",d);
	}
	
}
