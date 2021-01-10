#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> > q;
char s[1009][1009];
int a[1009][1009];
int dix[4]={0,0,1,-1},diy[4]={1,-1,0,0};
pair<int,int> u;
main()
{
	int m,n,k,i,j,x,y,ex,ey,d ;
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
	q.push({x,y});
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(u.first==ex&&u.second==ey)
		{
			printf("%d",a[u.first][u.second]);
			return 0 ;
		}
		for(i=0;i<4;i++)
		{
			for(d=1;d<=k;d++)
			{
				x=u.first+(d*dix[i]);
				y=u.second+(d*diy[i]);
				if(s[x][y]=='.'&&a[u.first][u.second]+1<a[x][y])
				{
					a[x][y]=a[u.first][u.second]+1;
					q.push({x,y});
				}
				else if(s[x][y]=='#'||a[u.first][u.second]>=a[x][y])
					break;
			}
		}
	}
	printf("-1");;
}
