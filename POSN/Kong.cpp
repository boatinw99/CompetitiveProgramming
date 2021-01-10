#include<stdio.h>
main()
{
	int n,m,input,i,j,max=0 ;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			a[i][0]=0;
			for(j=1;j<=m;j++)
			{
				scanf("%d",&input);
				a[i][j]=input;
			}
		}
		else if(i%2==1)
		{
			a[i][m]=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&input);
				a[i][j]=input;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		if(i%2==1)
		{
			a[i][0]+=a[i-1][1];
			for(j=1;j<m;j++)
			{
				if(a[i-1][j]>=a[i-1][j+1]) 
				{
					a[i][j]+=a[i-1][j];	
				}
				else if(a[i-1][j]<a[i-1][j+1])
				{
					a[i][j]=a[i][j]+a[i-1][j+1];
				}
			}
		}
		else if(i%2==0)
		{
			a[i][m]+=a[i-1][j-1];
			for(j=1;j<m;j++)
			{
				if(a[i-1][j-1]>a[i-1][j])a[i][j]+=a[i-1][j-1];
				else if(a[i-1][j-1]<a[i-1][j])
				{
					a[i][j]+=a[i-1][j];
				}
			}
		}
	
}
	for(i=0;i<=m;i++)
	{
		if(a[n-1][i]>max) max=a[n-1][i];
	}
	printf("%d",max);
}
