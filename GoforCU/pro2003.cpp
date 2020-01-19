#include<bits/stdc++.h>
using namespace std ;
int a[5][5][5][5][2];
int b[5][5][5][5];
char p[100009];
string s,c;
queue<pair<int,string> >q;
//M=1,F=2,B=3;
main()
{
	int n,i,j,k,x,y,k1,k2,k3,k4,co ;
	int a1,a2,a3,a4;
	scanf("%d ",&n);
	gets(p+1);
	q.push({1,"0000"});
	for(i=1;i<=n;i++)
	{
		if(p[i]=='M')x=1;
		else if(p[i]=='F')x=2;
		else x=3;
		while(q.front().first==i&&!q.empty())
		{
			s=q.front().second;
			a1=s[0]-'0'; a2=s[1]-'0'; a3=s[2]-'0' ; a4=s[3]-'0';
		//	printf("%d %d %d %d -> %d %c\n",a1,a2,a3,a4,a[a1][a2][a3][a4][0],p[i]);
			q.pop();
			c=x+'0';
			if(a1==0)
			{
				if(a[x][a2][a3][a4][1]!=0);
				else
				q.push({i+1,c+s[1]+s[2]+s[3]});
				a[x][a2][a3][a4][1]=max(a[x][a2][a3][a4][1],1+a[a1][a2][a3][a4][0]);
			}
			else if(a2==0)
			{
				if(a[a1][x][a3][a4][1]!=0);
				else
				q.push({i+1,s[0]+c+s[2]+s[3]});
				co=1;
				if(x!=a1)co++;
				a[a1][x][a3][a4][1]=max(co+a[a1][a2][a3][a4][0],a[a1][x][a3][a4][1]);
			}
			if(a3==0)
			{
				if(a[a1][a2][x][a4][1]!=0);
				else
				q.push({i+1,s[0]+(s[1]+(c+s[3]))});
				a[a1][a2][x][a4][1]=max(a[a1][a2][a3][a4][0]+1,a[a1][a2][x][a4][1]);
			}
			else if(a4==0)
			{
				if(a[a1][a2][a3][x][1]!=0);
				else 
				q.push({i+1,s[0]+(s[1]+(s[2]+c))});
				co=1;
				if(x!=a3)co++;
				a[a1][a2][a3][x][1]=max(a[a1][a2][a3][a4][0]+co,a[a1][a2][a3][x][1]);
			}
			if(a2!=0)
			{
				co=1;
				if(x!=a1)co++;
				if(x!=a2&&a1!=a2)co++;
				if(a[a2][x][a3][a4][1]==0)q.push({i+1,s[1]+c+s[2]+s[3]});
				a[a2][x][a3][a4][1]=max(a[a2][x][a3][a4][1],co+a[a1][a2][a3][a4][0]);
			}
			if(a4!=0)
			{
				co=1;
				if(x!=a3)co++;
				if(x!=a4&&a4!=a3)co++;
				if(a[a1][a2][a4][x][1]==0)q.push({i+1,s[0]+(s[1]+(s[3]+c))});
				a[a1][a2][a4][x][1]=max(a[a1][a2][a4][x][1],co+a[a1][a2][a3][a4][0]);
			}
		}
		for(k1=0;k1<=3;k1++)
		{
			for(k2=0;k2<=3;k2++)
			{
				for(k3=0;k3<=3;k3++)
				{
					for(k4=0;k4<=3;k4++)
					{
						a[k1][k2][k3][k4][0]=a[k1][k2][k3][k4][1];
						a[k1][k2][k3][k4][1]=0;
					}
				}
			}
		}
	}
	int max1=0;
	for(k1=0;k1<=3;k1++)
	{
		for(k2=0;k2<=3;k2++)
		{
			for(k3=0;k3<=3;k3++)
			{
				for(k4=0;k4<=3;k4++)
				{
					if(a[k1][k2][k3][k4][0]>max1)
					{
						max1=a[k1][k2][k3][k4][0];		
					}
			}
			}
		}
	}
	printf("%d",max1);
}
