#include<bits/stdc++.h>
using namespace std ;
set<pair<int,int> > e ;
int b[159][159],m,n,x2,y2,k=0,max1=9999999;
priority_queue<pair<int,pair<int,int> > > pq;
int Call(int value,int i,int j)
{
	if(i==x2&&j==y2)
	{
		k=99;
		if(value<max1)max1=value;
		return 0 ;
	}
	if(value+1<b[i+1][j]&&i<m-1&&b[i+1][j]>0)
	{
		b[i+1][j]=value+1;
		Call(value+1,i+1,j);
	}
	if(b[i-1][j]>value+1&&i>0&&b[i-1][j]>0)
	{
		b[i-1][j]=value+1;
		Call(value+1,i-1,j);
	}
	if(b[i][j+1]>value+1&&j<n-1&&b[i][j+1]>0)
	{
		b[i][j+1]=value+1;
		Call(value+1,i,j+1);
	}
	if(b[i][j-1]>value+1&&j>0&&b[i][j-1]>0)
	{
		b[i][j-1]=value+1;
		Call(value+1,i,j-1);
	}
	
}
main()
{
	int x1,y1,i,j,value,i1,j1,count=0;
	scanf("%d %d",&m,&n);
	int s[m][n];
	scanf("%d %d",&x1,&y1);
	x1--; y1--;
	scanf("%d %d",&x2,&y2);
	x2--; y2-- ;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %d",&s[i][j]);
			if(s[i][j]==1)s[i][j]=999999;
			else s[i][j]=-999999;
		}
	}
	s[x1][y1]=1;
	pq.push({1,{x1,y1}});
	while(!pq.empty())
	{
		value= pq.top().first;
		i=pq.top().second.first;
		j=pq.top().second.second;
		if(pq.top().first>0)
		{
			pq.pop();
			if(i<m-1&&value+1<s[i+1][j])
			{
				pq.push({value+1,{i+1,j}});
				s[i+1][j]=value+1;
			}
			if(i<m-1&&value+1<-s[i+1][j])
			{
				pq.push({-value-1,{i+1,j}});
				s[i+1][j]=-value-1;
			}
			//Down
			if(j<n-1&&value+1<s[i][j+1])
			{
				pq.push({value+1,{i,j+1}});
				s[i][j+1]=value+1;
			}
			if(j<n-1&&value+1<-s[i][j+1])
			{
				pq.push({-value-1,{i,j+1}});
				s[i][j+1]=-value-1;
			}
			//Right
			if(i>0&&value+1<s[i-1][j])
			{
				pq.push({value+1,{i-1,j}});
				s[i-1][j]=value+1;
			}
			if(i>0&&value+1<-s[i-1][j])
			{
				pq.push({-value-1,{i-1,j}});
				s[i-1][j]=-value-1;
			}
			//Up
			if(j>0&&value+1<s[i][j-1])
			{
				pq.push({value+1,{i,j-1}});
				s[i][j-1]=value+1;
			}
			if(j>0&&value+1<-s[i][j-1])
			{
				pq.push({-value-1,{i,j-1}});
				s[i][j-1]=-value-1;
			}
			//Left
		}
		else 
		{
			for(i1=0;i1<m;i1++)
			{
				for(j1=0;j1<n;j1++)
				{
					b[i1][j1]=s[i1][j1];
				}
			}
			k=0;
			Call(-value,i,j);
			if(k==99)count++;
			pq.pop();
		}
	}
	printf("%d\n%d",count,max1);
	
}
