#include<bits/stdc++.h>
using namespace std;
int n,m,co=0 ;
int dix[8]={0,0,1,1,1,-1,-1,-1};
int diy[8]={1,-1,-1,0,1,-1,0,1};
queue<pair<int,int> >q;
char s[2009][2009];
main()
{
	int i,j,k,p,x,y,l;
	scanf("%d %d ",&n,&m);
	for(i=0;i<n;i++)
	{
		gets(s[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(s[i][j]=='1')
			{
				co++;
				q.push({i,j});
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		s[x][y]='0';
		q.pop();
		for(l=0;l<=7;l++)
		{
			if(s[x+dix[l]][y+diy[l]]=='1'&&x+dix[l]>=0&&x+dix[l]<n&&y+diy[l]>=0&&y+diy[l]<m)s[x+dix[l]][y+diy[l]]='0',q.push({x+dix[l],y+diy[l]});
		}
	}
			}	
		}	
	}
	printf("%d",co);
}
