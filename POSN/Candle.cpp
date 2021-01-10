#include<bits/stdc++.h>
using namespace std ;
map<pair<int,int>,int> p ;
int a[2009][2009];
main()
{
	int m,n,i,j,k=1,count=0,i1,j1 ;
	scanf("%d %d ",&m,&n);
	char s[n+2];
	for(i=0;i<m;i++)
	{
		gets(s);
		for(j=0;j<n;j++)
		{
			if(s[j]=='0')
			{
				a[i][j]=0;
			}
			else a[i][j]=-1;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==-1)
			{
				count++;
				a[i][j]=k;
				k++;
				if(a[i][j+1]>0&&j+1<n)
				{
					i1=a[i][j];
					j1=a[i][j+1];
					count--;
					p[{i1,j1}]=99;
				}
				else if(a[i-1][j+1]>0&&i>0&&j+1<n)
				{
					i1=a[i][j];
					j1=a[i-1][j+1];
					count--;
					p[{i1,j1}]=99;
				}
				if(a[i+1][j-1]==-1)a[i+1][j-1]=a[i][j];
				if(a[i][j+1]==-1)a[i][j+1]=a[i][j];
				if(a[i+1][j]==-1)a[i+1][j]=a[i][j];
				if(a[i+1][j+1]==-1)a[i+1][j+1]=a[i][j];
			}
			else if(a[i][j]>0)
			{
				if(a[i][j+1]!=a[i][j]&&a[i][j+1]>0&&j+1<n)
				{
					i1=a[i][j];
					j1=a[i][j+1];
					if(p.find({i1,j1})==p.end())
					{
						count--;
						p[{i1,j1}]=99;
						p[{j1,i1}]=99;
					}
				}
				else if(a[i-1][j+1]!=a[i][j]&&a[i-1][j+1]>0&&i>0&&j+1<n)
				{
					i1=a[i][j];
					j1=a[i-1][j+1];
					if(p.find({i1,j1})==p.end())
					{
						count--;
						p[{i1,j1}]=99;
						p[{j1,i1}]=99;
					}
				}
				if(a[i+1][j-1]==-1)a[i+1][j-1]=a[i][j];
				if(a[i][j+1]==-1)a[i][j+1]=a[i][j];
				if(a[i+1][j]==-1)a[i+1][j]=a[i][j];
				if(a[i+1][j+1]==-1)a[i+1][j+1]=a[i][j];
			}
		}
		//printf("%d\n",count);
	}
/*	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}*/
		printf("%d",count);
}
