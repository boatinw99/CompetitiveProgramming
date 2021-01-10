#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[2][3][3];
ll B[3][3][3];
//turn x y ;
main()
{
	ll n,x,y,i,j,p,q,turn=1;
	scanf("%I64d %I64d %I64d",&n,&x,&y);
	for(p=0;p<2;p++)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%I64d",&A[p][i][j]);
				A[p][i][j]--;
			}
		}
	}
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		B[i][j][0]=-1;
	}
	ll temp,check,count,p1=0,p2=0;
	x--,y--;
	if(x==y+1||(x==0&&y==2))
	{
		p1++;
	}
	else if(y==x+1||(y==0&&x==2))
	{
		p2++;
	}
	for(turn=1;turn<n;)
	{
		if(B[x][y][0]==-1)
		{
			B[x][y][0]=turn;
			B[x][y][1]=p1;
			B[x][y][2]=p2;
			turn++;
			temp=x;
			x=A[0][x][y];
			y=A[1][temp][y];
			if(x==y+1||(x==0&&y==2))
			{
				p1++;
			}
			else if(y==x+1||(y==0&&x==2))
			{
				p2++;
			}
		}		
		else if(turn<n)
		{
			check=turn-B[x][y][0];
			if((n-turn)%check==0&&turn<n)
			{
				p1+=(p1-B[x][y][1])*(n-turn)/check;
				p2+=(p2-B[x][y][2])*(n-turn)/check;
				printf("%I64d %I64d",p1,p2);
				return 0 ;
			}
			else
			{
				if(n-turn<check)
				{
					B[x][y][0]=turn;
					B[x][y][1]=p1;
					B[x][y][2]=p2;
					temp=x;
					turn++;
					x=A[0][x][y];
					y=A[1][temp][y];
					if(x==y+1||(x==0&&y==2))
					{
						p1++;
					}
					else if(y==x+1||(y==0&&x==2))
					{
						p2++;
					}
				}
				else if((n-turn)%check!=0)
				{
					p1+=(p1-B[x][y][1])*((n-turn)/check);
					p2+=(p2-B[x][y][2])*((n-turn)/check);
					turn+=((n-turn)/check)*check;
					B[x][y][0]=turn;
					B[x][y][1]=p1;
					B[x][y][2]=p2;
					temp=x;
					turn++;
					x=A[0][x][y];
					y=A[1][temp][y];
					if(x==y+1||(x==0&&y==2))
					{
						p1++;
					}
					else if(y==x+1||(y==0&&x==2))
					{
						p2++;
					}
				}
			}
			//break; 
		}
	}
	printf("%I64d %I64d",p1,p2);
}

