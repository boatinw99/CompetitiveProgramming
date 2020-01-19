#include<bits/stdc++.h>
using namespace std;
int m,n,k,x,y,ex,ey ; 
char s[1009][1009];
bool b[1009][1009][4];
int a[1009][1009];
priority_queue<pair<pair<int,int>,pair<pair<int,int>,int> > > pq;
//{{co,ti},{{x,y},di}}
//
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
	pq.push({{0,0},{{x,y},-1}});
	a[x][y]=0;
	int count,ti,di;
	int max1=INT_MAX;
	while(!pq.empty())
	{
		printf("a ");
		count=pq.top().first.first*-1;
		ti=pq.top().first.second*-1;
		x=pq.top().second.first.first;
		y=pq.top().second.first.second;
		di=pq.top().second.second;
		pq.pop();
		if(count>=max1)
		{
			break;
		}
		if(x==ex&&y==ey)
		{
			max1=min(max1,count);
		}
		else
		{
			int co1=count,co2=count,co3=count,co4=count;
			int ti1=ti,ti2=ti,ti3=ti,ti4=ti;
			if(s[x-1][y]=='.'&&x>0) //Up
			{
				if(di==0)
				{
					ti1++;
					if(ti1>=k)
					co1++,ti=0;
				}
				else 
				{
					ti1=0;
					co1++;
				}
				if(co1<=a[x-1][y]&&b[x-1][y][0]==0)
				{
					pq.push({{-co1,-ti1},{{x-1,y},0}});
					b[x-1][y][1]=1;
					a[x-1][y]=co1;
				}
			}
			if(s[x+1][y]=='.'&&x<m-1) //Down
			{
				if(di==1)
				{
					ti2++;
					if(ti2>=k)
					co2++,ti2=0;
				}
				else 
				{
					ti2=0;
					co2++;
				}
				if(co2<=a[x+1][y]&&b[x+1][y][1]==0)
				{
					pq.push({{-co2,-ti2},{{x+1,y},1}});
					b[x+1][y][1]=1;
					a[x+1][y]=co2;
				}
			}
			if(s[x][y-1]=='.'&&y>0) //Left
			{
				if(di==2)
				{
					ti3++;
					if(ti3>=k)
					co3++,ti3=0;
				}
				else 
				{
					ti3=0;
					co3++;
				}
				if(co3<=a[x][y-1]&&b[x][y-1][2]==0)
				{
					pq.push({{-co3,-ti3},{{x,y-1},2}});
					b[x][y-1][2]=1;
					a[x][y-1]=co3;
				}
			}
			if(s[x][y+1]=='.'&&y<n-1) //Right
			{
				if(di==3)
				{
					ti4++;
					if(ti4>=k)
					co4++,ti4=0;
				}
				else 
				{
					ti4=0;
					co4++;
				}
				if(co4<=a[x][y+1]&&b[x][y+1][3]==0)
				{
					pq.push({{-co4,-ti4},{{x,y+1},3}});
					b[x][y+1][3]=1;
					a[x][y+1]=co4;
				}
			}
		}
	}
	if(max1==INT_MAX)printf("-1");
	else printf("%d",max1);
}

