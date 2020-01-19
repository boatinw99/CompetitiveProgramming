#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,a,b,i,l1,r1,l2,r2,l3,r3 ;
	scanf("%d %d %d",&n,&a,&b);
	int max1=0,max2=0,max3=0;
	max1=((n-b)/a*a)+b; l1=(n-b)/a; r1=1;
	if(l1>4)max1-=(l1-4)*a ,l1=4;
	if(2*b<=n)
	max2=((n-2*b)/a*a)+2*b,l2=(n-2*b)/a,r2=2;
	if(l2>4)l2=4;
	max3=(n/a*a),l3=n/a,r3=0;
	if(l3>4)max3=a*4,l3=4;
	int max0,l,r ;
	if(max1>max2)max0=max1,l=l1,r=r1;
	else max0=max2,l=l2,r=r2;
	if(max0<max3)max0=max3,l=l3,r=r3;
	int x=4,y=2,co=0;
	//printf("%d %d %d ",max0,l,r);
	//printf("\n%d\n\n",1^3);
	while(x>0||y>0)
	{
		int z=n;
		if(l<=x&&r<=y)
		{
			x-=l;
			y-=r;
		}
		else
		{
			while(z>=a&&x>0)x--,z-=a;
			while(z>=b&&y>0)y--,z-=b;
		}	
		co++;
	}
	printf("%d",co);
}
