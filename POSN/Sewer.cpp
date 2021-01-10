#include<bits/stdc++.h>
using namespace std ;
int m,n ;
map<pair<int,int>,int> p ;
priority_queue<pair<int,pair<int,int> > > pq ;
char s[100][100];
int Call(int i,int j,int a[100][100],int count)
{
	int i1,j1,b[m][n] ;
	a[i][j] = count;
	for(i1=0;i1<m;i1++)
	{
		for(j1=0;j1<n;j1++)
		b[i][j]=a[i][j];
	}
	if(p[{i,j}]==count&&p[{i,j}]>0)
	{
	p[{i,j}]=-count;	
	pq.push({-count,{i,j}});
	}
	else p[{i,j}]=count;
	//printf("%d %d %d\n",i,j,p[{i,j}]);
	if(s[i][j]=='B')
	{
		if(b[i+1][j]>=0)
		{
			Call(i+1,j,b,count+1);	
		}
		if(b[i][j+1]>=0)
		{
			Call(i,j+1,b,count+1);
		}
	}
	if(s[i][j]=='D')
	{
		if(b[i+1][j]>=0)
		{
			Call(i+1,j,b,count+1);
		}
	}
	if(s[i][j]=='R')
	{
		if(b[i][j+1]>=0)
		{
			Call(i,j+1,b,count+1);
		}
	}
//	printf("%d %d %d %d\n",a[0][0],a[1][0],a[2][0],a[0][1]);
	/*if(s[i-1][j]=='R'||s[i-1][j]=='B')
	{
		if(a[i-1][j]==0||count-a[i-1][j]==0)
		{
			
			Call(i-1,j,a,count+1);
		}
	}
	if(s[i][j-1]=='R'||s[i][j-1]=='B'||count-a[i][j-1]==0)
	{
		if(a[i][j-1]==0||count-a[i][j-1]==0)
		{
				
			Call(i,j-1,a,count+1);
		}
	}*/
	
}
main()
{
	int m,n,i,j,q[100][100] ;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %c",&s[i][j]);
		}
	}
	Call(0,0,q,1);
	//printf("%d\n%d %d",pq.top().first*-1,pq.top().second.first+1,pq.top().second.second+1);
}
