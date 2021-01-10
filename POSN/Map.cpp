#include<bits/stdc++.h>
using namespace std;
queue<pair<int,pair<int,int> > > q;
vector<pair<char,int> >v[200];
vector<pair<char,int> >::iterator it;
int s[400][400];
main()
{
	int m,n,i,j,max,x,y,i1,j1 ;
	char c,d;
	scanf("%d %d",&m,&n);
	max=m*n;
	while(max>1)
	{
		scanf("%d %c %d",&x,&c,&y);
		if(c=='L')d='R';
		else if(c=='U')d='D';
		v[x].push_back({c,y});
		v[y].push_back({d,x});
		max--;
	}
	s[m-1][n-1]=0;
	i1=m-1; j1=n-1;
  for(it=v[0].begin();it!=v[0].end();it++)
	{
		if(it->first=='L')
		{
			q.push({0,{m-1,n}});
			s[m-1][n]=it->second;
		}
		else if(it->first=='R')
		{
			q.push({0,{m-1,n-2}});
			s[m-1][n-2]=it->second;
			j1=n-2;
		}
		else if(it->first=='U')
		{
			q.push({0,{m,n-1}});
			s[m][n-1]=it->second;
		}
		else if(it->first=='D')
		{
			q.push({0,{m-2,n-1}});
			s[m-2][n-1]=it->second;
			i1=m-2;
		}
	}
	while(!q.empty())
	{
		x=q.front().first;
		i=q.front().second.first;
		j=q.front().second.second;
		q.pop();
		for(it=v[s[i][j]].begin();it!=v[s[i][j]].end();it++)
		{
			if(it->second!=x)
			{
				if(it->first=='L')
				{
					q.push({s[i][j],{i,j+1}});
					s[i][j+1]=it->second;
				}
				else if(it->first=='R')
				{
				//	q.push({s[i][j],{i,j-1}});
					s[i][j-1]=it->second;
					if(j-1<j1)j1=j-1;
				}
				else if(it->first=='U')
				{
			     	q.push({s[i][j],{i+1,j}});
					s[i+1][j]=it->second;
				}
				else if(it->first=='D')
				{
					q.push({s[i][j],{i-1,j}});
					s[i-1][j]=it->second;
					if(i-1<i1)i1=i-1;
				}	
			}
		}
		
	}
	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",s[i+i1][j+j1]);
			}
			printf("\n");
		}
	
}
