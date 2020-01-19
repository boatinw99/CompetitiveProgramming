#include<stdio.h>
main()
{
	int a,i,j,b[3]={1,0,0},c[100] ;
	char s[50];
	scanf("%d ",&a);
	for(i=0;i<a;i++)
	{
		gets(s);
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]=='A')
			{	if(b[0]==1)
				{
				b[0]=0;
				b[1]=1;	
				}
				
			}
			else if(s[j]=='B')
			{
				if(b[1]==1)
				{
					b[1]=0;
					b[2]=1;	
				}
			}
			else if(s[j]=='C')
			{	
				if(b[2]==1)
				{
					b[2]=0;
					b[0]=1;	
				}
			}
		}
		printf("%d %d %d ",b[0],b[1],b[2]);
		for(j=0;j<=2;j++)
		{
			if(b[j]==1)
			{
				c[i]=j+1;
			}
		}
		for(j=0;s[j]!='\0';j++)
		{
			s[j]='0';
		}
	}
	for(i=0;i<a;i++)
		printf("%d\n",c[i]);
}
