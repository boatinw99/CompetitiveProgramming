#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,b,x=0,y=0,e ;
	scanf("%d %d",&a,&b);
	if(a==b)
	{
		x=0; y=0;
	}
	else if(b==0)
	{
		x=0,y=0;
	}
	else 
	{
		x=1;
		e=a/3;
		if(a%3!=0)e++;
		if(b>=e)
		{
		   y=a-e-(b-e);	
		}
		else 
		{
			y=b*2;
		}
	}
	printf("%d %d",x,y);
}
