#include<bits/stdc++.h>
using namespace std ;
char s[1000][1000];
bool a[1000][1000];
queue<pair<pair<int,int>,pair<int,int> > > pq;
//L R U D 0 1 2 3
main()
{
	int m,n,i,j,x,y,d,count,xs,ys ;
	char q[1000];
	scanf("%d %d ",&m,&n);
	for(i=0;i<m;++i)
	{
		gets(q);
		for(j=0;j<n;++j)
		{
			s[i][j]=q[j];
			if(s[i][j]=='S')
			{
				a[i][j]=1;
				pq.push({{-1,-1},{i,j}});
			}
			if(s[i][j]=='T')
			{
				xs=i;
				ys=j;
			}
		}
	}
	while(!pq.empty())
	{
		count=pq.front().first.first;
		d=pq.front().first.second;
		x=pq.front().second.first;
		y=pq.front().second.second;
		a[x][y]=1;
		if(x==xs&&y==ys)
		{
			printf("YES");
			return 0;
		}
		pq.pop();
		//printf("%d %d %d %d\n",count,d,x,y);
		if(y>0&&s[x][y-1]!='*'&&!a[x][y-1])
		{
		//	printf("L");
			if(d==0)
			{
				pq.push({{count,0},{x,y-1}});
			}
			else if(count+1<3)
			{
				pq.push({{count+1,0},{x,y-1}});
			}
		}
		if(y<n-1&&s[x][y+1]!='*'&&!a[x][y+1])
		{
		//	printf("R");
			if(d==1)
			{
				pq.push({{count,1},{x,y+1}});
			}
			else if(count+1<3)
			{
				pq.push({{count+1,1},{x,y+1}});
			}
		}
		if(x>0&&s[x-1][y]!='*'&&!a[x-1][y])
		{
		//	printf("U");
			if(d==2)
			{
				pq.push({{count,2},{x-1,y}});
			}
			else if(count+1<3)
			{
				pq.push({{count+1,2},{x-1,y}});
			}
		}
		if(x<m-1&&s[x+1][y]!='*'&&!a[x+1][y])
		{
		//	printf("D");
			if(d==3)
			{
				pq.push({{count,3},{x+1,y}});
			}
			else if(count+1<3)
			{
				pq.push({{count+1,3},{x+1,y}});
			}
		}
	}
	printf("NO");
}
