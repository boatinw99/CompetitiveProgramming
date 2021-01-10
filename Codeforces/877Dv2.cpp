#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int x,y,ex,ey;
char s[1009][1009];
int a[1009][1009];
queue<pair<int,pair<int,int> > > q;
main()
{
	int i,j;
	scanf("%d %d %d",&m,&n,&k);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %c",&s[i][j]);
			a[i][j]=INT_MAX;
		}
	}
	scanf("%d %d %d %d",&x,&y,&ex,&ey);
	x--;y--;ex--;ey--;
	a[x][y]=0;
	int ti,ti1,count=0;
	q.push({0,{x,y}});
	while(!q.empty())
	{
		ti1=q.front().first;
		x=q.front().second.first;
		y=q.front().second.second;
		q.pop();
		ti1++;
		count=0;
		ti=ti1;
		for(i=x-1;i>=0;i--)
		{
			count++;
			if(s[i][y]=='#'||a[i][y]!=INT_MAX)break;
			else
			{
				if(count>k)count=0,ti++;
				a[i][y]=ti;
				q.push({ti,{i,y}});
			}
		}
		ti=ti1,count=0;
		for(i=x+1;i<m;i++)
		{
			count++;
			if(s[i][y]=='#'||a[i][y]!=INT_MAX)break;
			else
			{
				if(count>k)count=0,ti++;
				a[i][y]=ti;
				q.push({ti,{i,y}});
			}
		}
		ti=ti1,count=0;
		for(j=y-1;j>=0;j--)
		{
			count++;
			if(s[x][j]=='#'||a[x][j]!=INT_MAX)break;
			else
			{
				if(count>k)count=0,ti++;
				a[x][j]=ti;
				q.push({ti,{x,j}});
			}
		}
		ti=ti1,count=0;
		for(j=y+1;j<n;j++)
		{
			count++;
			if(s[x][j]=='#'||a[x][j]!=INT_MAX)break;
			else
			{
				if(count>k)count=0,ti++;
				a[x][j]=ti;
				q.push({ti,{x,j}});
			}
		}
	}
	printf("%d",a[ex][ey]);
		
	
	
	
	
}
