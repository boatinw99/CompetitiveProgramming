#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int m=20,x,y,z ;
	while(m--)
	{
		scanf("%d %d",&x,&y);
		if(y*2>x)printf("0\n");
		else
		{
			z=x/2-y;
			printf("%d\n",(x-4*z)/2+1);
		}
	}
}
