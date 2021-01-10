#include<bits/stdc++.h>
using namespace std ;
queue<pair<int,pair<pair<int,int>,pair<int,int> > > > pq;
set<pair<int,int> > e ;
main()
{
	int m,n,x1,y1,x2,y2,i,j,value,count=0,max=99999,x,y,k=0 ;
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
		if(s[i][j]==0)s[i][j]=-1;	
		else s[i][j]=99;
		}
	}
	s[x1][y1]=1;
	pq.push({1,{{-1,-1},{x1,y1}}});
	while(!pq.empty())
	{
		value=pq.front().first ;
		x1=pq.front().second.second.first ;
		y1=pq.front().second.second.second ;
		i=pq.front().second.first.first;
		j=pq.front().second.first.second ;
		pq.pop();
		printf("%d %d -> %d %d\n",x1,y1,i,j);
		if(x1==x2&&y1==y2)
		{
			if(value<max){max=value;}
			//printf("%d %d -> %d %d\n",x1,y1,i,j);
			e.insert({i,j});
		}
		else 
		{
		if((value<s[x1+1][y1]&&x1<m-1)||(x1+1==x2&&y1==y2))
		{
			pq.push({value+1,{{i,j},{x1+1,y1}}});
			s[x1+1][y1]=value+1;
		}
		else if(s[x1+1][y1]==-1&&i==-1&&x1<m-1)
		{
			pq.push({value+1,{{x1+1,y1},{x1+1,y1}}});
			//printf("%d %d -> %d %d\n",x1,y1,i,j);
		}
		//Down
		if((value<s[x1-1][y1]&&x1>0)||(x1-1==x2&&y1==y2))
		{
			pq.push({value+1,{{i,j},{x1-1,y1}}});
			//printf("%d %d\n",x1-1,y1);
			s[x1-1][y1]=value+1;
		}
		else if(s[x1-1][y1]==-1&&i==-1&&x1>0)
		{
			pq.push({value+1,{{x1-1,y1},{x1-1,y1}}});
			//printf("%d %d -> %d %d\n",x1,y1,i,j);
		}
		//Up
		if((value<s[x1][y1-1]&&y1>0)||(x1==x2&&y1-1==y2))
		{
			pq.push({value+1,{{i,j},{x1,y1-1}}});
			s[x1][y1-1]=value+1;
		}
		else if(s[x1][y1-1]==-1&&i==-1&&y1>0)
		{
			pq.push({value+1,{{x1,y1-1},{x1,y1-1}}});
			//printf("%d %d -> %d %d\n",x1,y1,i,j);
		}
		//Left
		if((value<s[x1][y1+1]&&y1<n-1)||(x1==x2&&y1+1==y2))
		{
			pq.push({value+1,{{i,j},{x1,y1+1}}});
			s[x1][y1+1]=value+1;
		}
		else if(s[x1][y1+1]==-1&&i==-1&&y1<n-1)
		{
			pq.push({value+1,{{x1,y1+1},{x1,y1+1}}});
			//printf("%d %d -> %d %d\n",x1,y1,i,j);
		}
		//right
		}
	/*	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			printf("%d ",s[i][j]);
			printf("\n");
		}
		printf("\n");*/
	}
	printf("\n");
	count = e.size();
	printf("%d\n%d",count,max);
}
