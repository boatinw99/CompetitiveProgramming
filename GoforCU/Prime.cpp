#include<stdio.h>
int n,i,m,j,p=1;
int s[500009];
main()
{
	bool k=0;
	scanf("%d",&n);
	s[0]=2;
	for(i=3;n-1;i+=2)
	{
		k=0;
		for(j=0;j<p&&s[j]*s[j]<=i;j++)
		{
			if(i%s[j]==0)
			{
				k=1;
				break;
			}
		}
		if(!k)n--,s[p++]=i;
	}
	printf("%d",s[p-1]);
}
