#include<stdio.h>
main()
{
	int m,n,i,j,square;
	scanf("%d %d %d",&m,&n,&square);
	int s[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		scanf(" %d",&s[i][j]);
	}
	for(i=1;i<m;i++)
	{
		s[i][0]+=s[i-1][0];
	}
	for(j=1;j<n;j++)
	{
		s[0][j]+=s[0][j-1];
	}
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			s[i][j]=s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",s[i][j]);
		printf("\n");
	}
}
