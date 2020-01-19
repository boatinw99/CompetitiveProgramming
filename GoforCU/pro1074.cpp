#include<bits/stdc++.h>
using namespace std ;
int n,m ;
char s[109][109];
bool b[109][109];
int check(int i,int j,int r)
{
	bool k=0;
	int x,y;
	for(x=0;x<r;x++)
	{
		if(s[i-x][j]=='.')
		{
			k++; break;
		}
	}
	for(y=0;y<r;y++)
	{
		if(s[i][j-y]=='.')
		{
			k++;
			break;
		}
	}
	if(k)return r-1;
	if(i+1<n&&j+1<m)check(i+1,j+1,r+1);
	else return r;
}
int pr(int i,int j)
{
	int x,y,r=0,e=0;
	if(j+1<m&&b[i][j+1])
	{
		for(x=0;s[i+x][j]=='x';x++)r++;
		printf("%d %d %d",i+1,j+1,r);
		return 0;
	}
	if(j>0&&b[i][j-1])
	{
		for(x=0;s[i+x][j]=='x';x++)r++;
		for(y=0;s[i][j+y]=='x';y++)e++;
		printf("%d %d %d",i+1,j+1-(r-e),r);
		return 0;
	}
	if(i>0&&b[i-1][j])
	{
		for(y=0;s[i][j+y]=='x';y++)r++;
		for(x=0;s[i+x][j]=='x';x++)e++;
		printf("%d %d %d",i+1-(r-e),j+1,r);
		return 0;
	}
	else
	{
		for(x=0;s[i+x][j]=='x';x++)r++;
		printf("%d %d %d",i+1,j+1,r);
		return 0;
	}
}
main()
{
	int i,j,l,i1,j1,r=1,x,y,r1;
	scanf("%d %d ",&n,&m);
	for(i=0;i<n;i++)
	{
		gets(s[i]);
	}
	bool k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{ b[i][j]=0;
			if(s[i][j]=='x')
			{
				k++;
				if(i+1<n&&j+1<m)
				{
					r=check(i+1,j+1,2);
				}	
				break;
			}
		}
		if(k)break;
	} if(i==n)return 0*printf("1 1 0\n1 1 0");
	printf("%d %d %d\n",i+1,j+1,r);
	i1=i,j1=j,r1=r;
	for(x=0;x<r;x++)for(y=0;y<r;y++)b[x+i][y+j]++;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!b[i][j]&&s[i][j]=='x')
			{
				pr(i,j);
				return 0;
			}
		}
	}
	printf("%d %d %d",i1+1,j1+1,1);
}
