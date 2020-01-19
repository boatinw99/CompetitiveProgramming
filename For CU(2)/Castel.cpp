#include<stdio.h>
int a[100][100],count=0;
int m,n,max=0 ;
int Call(int i,int j)
{
	//a[i][j]=1;
	if(i>0&&a[i-1][j]==0)
	{
		count++;
		a[i-1][j]=1;
		Call(i-1,j);
	}
	if(i<m-1&&a[i+1][j]!=1)
	{
		count++;
		a[i+1][j]=1;
		Call(i+1,j);
	}
	if(j>0&&a[i][j-1]==0)
	{
		count++;
		a[i][j-1]=1;
		Call(i,j-1);	
	}
	if(j<n-1&&a[i][j+1]==0)
	{
		count++;
		a[i][j+1]=1;
		
		Call(i,j+1);
	}
	if(count>max)max=count;
}
main()
{
	int i,j,d,k=0 ;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		scanf("%d",&d);
		a[i][j]=d;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				k++;	
				count=0;
				Call(i,j);
			}
		}
	}
	printf("%d\n%d",k,max);
}
