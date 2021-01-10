#include<bits/stdc++.h>
using namespace std ;
main()
{
	int c,v0,v1,a,l,x ;
	scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
	int day=1,count=v0;
	while(count<c)
	{
		day++;
		v0+=a;
		x=v0-l;
		if(x>v1)x=v1;
		count+=x;
	}
	printf("%d",day);
	
}
