#include<bits/stdc++.h>
using namespace std;
int l,r;
int a[2][509][509],nona[2][509][509],tunga[2][509][509];
main()
{
	int m1,n1,m2,n2,i,j,k,x,y,z ;
	scanf("%d %d",&m1,&n1);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&x,&y);
		a[0][x][y]++;
	}
	scanf("%d %d",&m2,&n2);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&x,&y);
		a[1][x][y]++;
	}
	z=0;
		for(i=0;i<m1;i++)
		{
			nona[z][i][0]=a[z][i][0];
			for(j=1;j<n1;j++)nona[z][i][j]=nona[z][i][j-1]+a[z][i][j];
		}
		for(j=0;j<n1;j++)
		{
			tunga[z][0][j]=a[z][0][j];
			for(i=1;i<m1;i++)tunga[z][i][j]=tunga[z][i-1][j]+a[z][i][j];	
		}
	z=1;
		for(i=0;i<m2;i++)
		{
			nona[z][i][0]=a[z][i][0];
			for(j=1;j<n2;j++)nona[z][i][j]=nona[z][i][j-1]+a[z][i][j];
		}
		for(j=0;j<n2;j++)
		{
			tunga[z][0][j]=a[z][0][j];
			for(i=1;i<m2;i++)tunga[z][i][j]=tunga[z][i-1][j]+a[z][i][j];	
		}
	z=0;int mid; bool d=0;
	for(mid=500;mid>=1;mid--)
	{
		for(i=0;i+mid<=m1;i++)
		{
			for(j=0;j+mid<=n1;j++)
			{
				if(!a[z][i][j]&&nona[z][i][j+mid-1]==nona[z][i][j]&&nona[z][i+mid-1][j]==nona[z][i+mid-1][j+mid-1]&&tunga[z][i+mid-1][j]==tunga[z][i][j]&&tunga[z][i+mid-1][j+mid-1]==tunga[z][i][j+mid-1])   	                   
				{
					d=1;
					break;
				}
			}
			if(d==1)break;
		}
		if(d==1)
		{
			printf("%d",mid);
			break;	
		}
	}
	z=1;d=0;
	for(mid=500;mid>=1;mid--)
	{
		for(i=0;i+mid<=m2;i++)
		{
			for(j=0;j+mid<=n2;j++)
			{
				if(!a[z][i][j]&&nona[z][i][j+mid-1]==nona[z][i][j]&&nona[z][i+mid-1][j]==nona[z][i+mid-1][j+mid-1]&&tunga[z][i+mid-1][j]==tunga[z][i][j]&&tunga[z][i+mid-1][j+mid-1]==tunga[z][i][j+mid-1])   	                   
				{
					d=1;
					break;
				}
			}
			if(d==1)break;
		}
		if(d==1)
		{
			printf("\n%d",mid);
			return 0;
		}
	}
}
