#include<stdio.h>
int p,b[101]={0},i=0;
Call(int a)
{   
	if(a<=p)
	{
		if(b[a]==0)
		{
			b[a]++;
		}
		Call(a+6);
		Call(a+9);
		Call(a+20);
	}
}
main()
{   int j,k=99;
	scanf("%d",&p);
	Call(6);
	Call(9);
	Call(20);
	for(j=0;j<101;j++)
		if(b[j]==1)
			{
			printf("%d\n",j);
			k=1;
			}
	if(k==99)
	{
		printf("no");		
	}		
			

}
